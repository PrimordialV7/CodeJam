#include<stdio.h>           
#include<stdlib.h>          
#include<string.h>         

int main()  
{
	int t;
    int i,j,x;

    scanf("%d\n",&t);       //Number of test cases 't'
   
	if(t<1 || t>100)        //'t' has limit of 1-100
        exit(0);
   
	char s[t][t*100];        //Pancake arrays for 't' cases
    int k[t];		//Flipper size 
	int c[t];	   //Counter for no.of flips
	int m[t];     //Impossible case 
    
	for(i=0;i<t;i++)        //Loop for 't' cases
    {
        
		scanf("%s",s[i]);   //Pancake array 's' input
        scanf("%d",&k[i]);  //Flipper size 'k'
   
	}
    
	for(x=0;x<t;x++)        //Loop for 't' cases
    {
       
		c[x]=0;             //Initialise flip counter to 0
        
		for(i=0;s[x][i]!='\0';i++)      //Loop for every pancake in array
        {
        
            if(s[x][i]=='-' && s[x][i+k[x]-1]!='\0')  //Check if pancake is '-' and fits size of array
            {
               
				for(j=0;j<k[x];j++)                 //Loop to flip 'k' pancakes at once
                {
                        
					if(s[x][i+j]=='-')          //Check if pancake is blank side to make it happy side up
                        {
                          
							s[x][i+j]='+';           
                        
						}
                        
					else                    //Vice versa    
                        
					{   
                           
						s[x][i+j]='-';		
                        
					}
                
				}
               
				c[x]++;             //Counter increments every time flipper is used
           
			}
       
		}
    
	}
    
	for(i=0;i<t;i++)                //Loop for 't' cases
    {
       
		for(j=0;s[i][j]!='\0';j++)  //Loop for every pancake in array
        {
	        
			if(s[i][j]=='-')        //Check if any blank sides available
	        {
	        	
				m[i]++;             //Counter increments if any blank side available
	       
			}
	        
			else
	        {
	            
				continue;           //Else skips current iteration of loop
	        
			}
        
		}
    
	}
   
	for(i=0;i<t;i++)                //Loop 't' Cases to display result
    {
        
		printf("Case #%d: ",i+1);
	    
		if(m[i]>0)                  //If counter more than 0 then its an impossible case
	    {
		    
			printf("IMPOSSIBLE\n");
	    
		}
	    
		else                        //Else displays Counter for no. of flips
	    {
            
			printf("%d\n",c[i]);
	    
		}
    
	}
    
	return 0;                       
}
     
