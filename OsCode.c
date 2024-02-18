#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
	int fd[2];
	if(pipe(fd) == -1)
	{
		printf("an error occured");
		return 1;
	}
	int id = fork();
	if(id == 0)
	{
		close(fd[1]);
		int i;
		int j;
		int satir2;
		int sutun2;
		int matris2[50][50];
		int transpozmatris[50][50];
		read(fd[0], &satir2, sizeof(int));
		read(fd[0], &sutun2, sizeof(int));
		read(fd[0], &matris2, sizeof(matris2));
		close(fd[0]);
		for(i=0; i<satir2; ++i)
		{
        		for(j=0; j<sutun2; ++j)
        		{
            			transpozmatris[j][i] = matris2[i][j];
        		}	
        	}
        	printf("Child Process:\n");
        	for(i=0; i<sutun2; ++i)
		{
        		for(j=0; j<satir2; ++j)
        		{
        			printf("%d ",transpozmatris[i][j]);
        		}	
        		printf("\n");
        		
        	}
        	printf("\nParent Process:\n");
		for(i=0; i<satir2; ++i)
		{
        		for(j=0; j<sutun2; ++j)
        		{
	
        			printf("%d ",matris2[i][j]);
        		}
        		printf("\n");
        		
        	}
	}
	else
	{
		close(fd[0]);
    		int satir;
    		int sutun;
    		int eleman;
		int i = 0;
		int j = 0;
		int matris[50][50];
		int c = 0;
		int t=0,k=0;
		int p;
		scanf("%d",&satir);
		scanf("%d",&sutun);
		int carpim = satir * sutun;
   	 	for(p=0; p<carpim; p++) 
		{
    			scanf("%d",&eleman);
			if(j <satir)
			{
				if(i <sutun)
				{
					matris[j][i] = eleman;
				}
				else
				{
					j++;
					i = 0;
					matris[j][i] = eleman;
				}
				i++;
			}
		}
	
		write(fd[1],&satir,sizeof(int));
		write(fd[1],&sutun,sizeof(int));
		write(fd[1],&matris,sizeof(matris));
		close(fd[1]);
	}
    
    return 0;
}
