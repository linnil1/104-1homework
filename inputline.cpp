// it is for double !!
bool digInLine(double *arr,int &n){	// input in a line 
	puts("input in a line ");
	char c[10000];
	if(fgets(c,10000,stdin)==NULL){//not NULL 
		return 0;
	}
	n=0;
	char *now=strtok(c," \n");// use strtok the separate space
	while(now!=NULL){//foolproof
		int dot = 0,mus=0,ok=1;
		char *st=now;
		for (; *now  && dot<=1 && ok && mus<=1; ++now)
			if (isdigit(*now))
				continue;
			else if (*now == '-')
				++mus;
			else if (*now == '.')
				++dot;
			else
				ok = 0; 
		if (dot > 1 || mus >1)
			ok = 0; 
		if (!ok)
			printf("%s is not a number !! i will ignore it !!\n",st);
		else
			arr[n++] = atof(st);
		now = strtok(NULL," \n");
	}
	return 1;
}

