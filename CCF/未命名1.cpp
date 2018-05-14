#ifndef __CPUINFO_H
#define __CPUINFO_H
void CreatePageOne(GtkWidget *notebook);   //CPU
void DrawingCPU(void);
gint refresh_cpu(gpointer data);
static gboolean cpu_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data);
static gboolean cpu_configure_event(GtkWidget *widget, GdkEventConfigure *event, gpointer data);
float getCpuUseRatio(int n);
void GetCpuInfo();
void GetInfo(char *path, char *name, char info[]);

GtkWidget *draw_cpu;
GtkWidget *window;
GtkWidget *labelofcpu; //cpu rate
GtkWidget *infolabel;  //cpu infomation
GdkPixmap *cpu_graph;
/* 全局变量 */
static gint cpuPoints[100];
static gfloat cpu_rate = 0.0;
float zuser = 0, ztotal = 0, zidle = 0;
char cpuBuffer[2000];

static gboolean cpu_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
	gdk_draw_drawable(widget->window, widget->style->fg_gc[GTK_WIDGET_STATE(
			widget)], cpu_graph, event->area.x, event->area.y, event->area.x,
			event->area.y, event->area.width, event->area.height);
	return FALSE;
}
static gboolean cpu_configure_event(GtkWidget *widget, GdkEventConfigure *event, gpointer data)
{
	if (cpu_graph)
	{
		g_object_unref(cpu_graph);
	}
	cpu_graph = gdk_pixmap_new(widget->window, widget->allocation.width,
			widget->allocation.height, -1);
	gdk_draw_rectangle(cpu_graph, widget->style->white_gc, TRUE, 0, 0,
			widget->allocation.width, widget->allocation.height);
	return TRUE;
}


/* 取得cpu利用率 */
float getCpuUseRatio(int n)//1:user 2:sys 3:iowait
{
	FILE *fp;
	char buffer[1024];
	size_t buf;
	float useRatio;
	float sysRatio;
    	float iowaitRatio;
	/* 分别为用户模式，低优先级用户模式，内核模式，空闲的处理器时间 */
	float user = 0, nice = 0, sys = 0, idle = 0, iowait = 0;
	fp = fopen("/proc/stat", "r");
	/* 从fp中读取sizeof(buffer)块数据放入buffer，每次读一块 */
	buf = fread(buffer, 1, sizeof(buffer), fp);
	fclose(fp);
	if (buf == 0)
		return 0;
	buffer[buf] == '\0';
	sscanf(buffer, "cpu %f %f %f %f %f", &user, &nice, &sys, &idle, &iowait);
	if (idle <= 0)
		idle = 0;
	useRatio = 100 * (user - zuser) / (idle - zidle);
	sysRatio = 100 * sys / user;
	iowaitRatio = 1000 * iowait / idle;

	if (useRatio > 100)
		useRatio = 100;
	ztotal = user + nice + sys + idle;
	zuser = user;
	zidle = idle;
	cpu_rate = useRatio;
	if(n == 1)
		return useRatio;
	else if(n == 2)
		return sysRatio;
	else if(n == 3)
		return iowaitRatio;
}



void CreatePageOne(GtkWidget *notebook)   //CPU
{
	GtkWidget *vbox, *frame, *CPUframe, *infoframe;

	frame = gtk_frame_new("CPU");
	gtk_container_set_border_width(GTK_CONTAINER(frame), 10);
	gtk_widget_show(frame);

	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), frame, gtk_label_new("\tCPU\t"));

	GtkWidget *table = gtk_table_new(10, 10, TRUE);
	gtk_container_add(GTK_CONTAINER(frame), table);

	CPUframe = gtk_frame_new("CPU使用曲线");
	gtk_table_attach_defaults(GTK_TABLE(table), CPUframe, 1, 9, 0, 5);
	gtk_widget_show(CPUframe);

	infoframe = gtk_frame_new("CPU information");
	gtk_table_attach_defaults(GTK_TABLE(table), infoframe, 0, 10, 5, 10);
	gtk_widget_show(infoframe);
	infolabel = gtk_label_new("");

	gtk_container_add(GTK_CONTAINER(infoframe), infolabel);
	gtk_widget_show(infolabel);
	GetCpuInfo();
	gtk_widget_show(table);

	draw_cpu = gtk_drawing_area_new();
	gtk_widget_set_app_paintable(draw_cpu, TRUE);
	gtk_drawing_area_size(GTK_DRAWING_AREA(draw_cpu), 40, 80);
	gtk_container_add(GTK_CONTAINER(CPUframe), draw_cpu);
	gtk_widget_show(draw_cpu);

	DrawingCPU();

}

void DrawingCPU()
{
	int i;
	for (i = 0; i < 100; i++)
	{
		/* 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
		 * (rand() % (b - a)) + a */
		cpuPoints[i] = 999;
	}
	g_signal_connect(draw_cpu, "expose_event",G_CALLBACK(cpu_expose_event), NULL);
	g_signal_connect(draw_cpu, "configure_event", G_CALLBACK(cpu_configure_event), NULL);
	gtk_widget_show(draw_cpu);
}

gint refresh_cpu(gpointer data)
{
	/* 建矩形绘图区 */
	GdkGC *gc_chart_cpu = gdk_gc_new(draw_cpu->window);
	/* 背景颜色 */
	GdkColor color;
	color.red = 0xFFFF;
	color.green = 0xFFFF;
	color.blue = 0xFFFF;
	gdk_gc_set_rgb_fg_color(gc_chart_cpu, &color);
	int width, height, curPoint, step;
	cpu_rate = getCpuUseRatio(1) / 100;
	gdk_draw_rectangle(cpu_graph, gc_chart_cpu, TRUE, 0, 0,draw_cpu->allocation.width, draw_cpu->allocation.height);
	width = draw_cpu->allocation.width;
	height = draw_cpu->allocation.height;
	curPoint = (int) (cpu_rate * (double) height);
	cpuPoints[99] = height - curPoint;
	int i;
	for (i = 0; i < 99; i++)
		cpuPoints[i] = cpuPoints[i + 1];
	step = width / 99;
	GdkGC *gc = gdk_gc_new(GDK_DRAWABLE(cpu_graph));
	gdk_color_parse("black", &color);
	gdk_gc_set_foreground(gc, &color);
	gdk_gc_set_line_attributes(gc, 1, GDK_LINE_SOLID, GDK_CAP_ROUND,GDK_JOIN_MITER);
	for (i = 99; i >= 1; i--)
		gdk_draw_line(GDK_DRAWABLE(cpu_graph), gc, i * step, cpuPoints[i], (i - 1) * step, cpuPoints[i - 1]); 
	gtk_widget_queue_draw(draw_cpu);

	GetCpuInfo();
	
	return TRUE;
}

void GetCpuInfo()
{
	char modeName[50], cpuMHz[20], cacheSize[20], cpuCores[20], addrSize[50];
	char *p;
	GetInfo("/proc/cpuinfo", "model name", modeName);
	GetInfo("/proc/cpuinfo", "cache size", cacheSize);
	GetInfo("/proc/cpuinfo", "cpu MHz", cpuMHz);
	GetInfo("/proc/cpuinfo", "cpu cores", cpuCores);
	GetInfo("/proc/cpuinfo", "address sizes", addrSize);

	strcpy(cpuBuffer, "\nCPU型号和主频:\n");
	p = strtok(modeName, "\n");
	strcat(cpuBuffer, p);

	//strcat(cpuBuffer, "\n\n寻址位数:");
	//p = strtok(addrSize, "\n");
	//strcat(cpuBuffer, p);

	strcat(cpuBuffer, "\n\nCPU 主频:");
	p = strtok(cpuMHz, "\n");
	strcat(cpuBuffer, p);
	strcat(cpuBuffer, " MHz");

	strcat(cpuBuffer, "\n\nCACHE 大小:");
	p = strtok(cacheSize, "\n");
	strcat(cpuBuffer, p);

	strcat(cpuBuffer, "\n\nCPU核数:");
	p = strtok(cpuCores, "\n");
	strcat(cpuBuffer, p);

	gtk_label_set_text(GTK_LABEL(infolabel), cpuBuffer);


}

//get info(name) from file path
void GetInfo(char *path, char *name, char info[])
{
	int fd = open(path, O_RDONLY);
	char temp[1000];
	int k = 0;
	read(fd, temp, sizeof(temp));
	close(fd);
	char *p = NULL;
	p = strstr(temp, name);
	while(*p != ':')
		p++;
	//p = p + 2;
	p++;
	while(*p == ' ')
		p++;
	while(*p != '\n')
	{
		info[k] = *p;
		p++;
		k++;
	}
	info[k] = '\n';
	info[k+1] = '\0';
}

#endif
