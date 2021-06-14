double delta_find_degree(double x,double y,double heading)//stanley method
{
	double degree_usv;//无人船->目标点角度
	double delta1;//艏向与切向夹角
	double delta_sum_result;

	delta1 = heading - degree[num_curr];
	if(delta1>M_PI) delta1=delta1-2*M_PI;
	if(delta1<-M_PI) delta1=delta1+2*M_PI; //delta1<0顺时针转 +
	printf("delta1=%lf\n",delta1);
	double e_dis;
	double dis_u2p=sqrt((a[num_curr][0]-x)*(a[num_curr][0]-x)+(a[num_curr][1]-y)*(a[num_curr][1]-y));

	//计算无人船->目标点角度
	degree_usv=atan((a[num_curr][0]-x)/(a[num_curr][1]-y)); 
	if(a[num_curr][1]<=y&&a[num_curr][0]>x) degree_usv=M_PI+degree_usv;
	if(a[num_curr][1]<=y&&a[num_curr][0]<=x) degree_usv=-M_PI+degree_usv;
	double judge_delta_degree=degree_usv-degree[num_curr];
	if(judge_delta_degree>M_PI) judge_delta_degree=judge_delta_degree-2*M_PI;
	if(judge_delta_degree<-M_PI) judge_delta_degree=judge_delta_degree+2*M_PI;
	e_dis=fabs(dis_u2p*sin(judge_delta_degree));
	double et=atan(k*e_dis*e_dis/vt/2);
	if(judge_delta_degree>=0)
	{
		et=-et;
	}
	delta_sum_result = et+delta1;
	if(delta_sum_result>M_PI) delta_sum_result=delta_sum_result-2*M_PI;
	if(delta_sum_result<-M_PI) delta_sum_result=delta_sum_result+2*M_PI; //delta1<0顺时针转 +
	track_log<<setprecision(12)<<e_dis<<","<<setprecision(12)<<et<<",";
	printf("e_dis=%lf,et=%lf,",e_dis,et);
	
	track_log<<setprecision(12)<<delta_sum_result<<",";
	printf("delta=%lf\n",delta_sum_result);
	return delta_sum_result;
}
