#include<stdio.h>               
#include<stdlib.h>             
#include<string.h> 

int main()
{
	int t;                      //Declare 't' Cases
	scanf("%d",&t);             //Read number of test cases 't'
	
	if(t<1||t>100)              //'t' has limit of 1-100
		exit(0);
	
	unsigned long n[t];         //Input number
	int k[t][18];               //Array for number of digits
	int i=0;
	int len[t];              //Length of each number
	
	while(i<t)
	{                 //For every 't' case
	
		unsigned long r,d;    
		
		len[i]=0;            //Initialising length as 0
		scanf("%lu",&n[i]);     //Input number 'n'
		r = n[i]/10;            //To retrieve number of digits, Divide by 10   
    	d = 1;  
		
		while(d < r)            //Loop the r times while multiplying by 10                
        	   		d = d*10;        //The number of digits will be equalent to n+1 from d=10^n
		int j=0;
    
    	while(d)
    	{                               
		
			k[i][j++]=n[i] / d;     //Retrieve every digit and assign them into the integer array
       		n[i] %= d;              //Modulus the main number
        	d = d/10;                //Divide d by 10 every loop
			len[i]++;            //Counter increments for every digit added
    
    	}
	
		i++;
	}
	
	i=0;
	
	while(i<t)
	{                     //For Every case
	
		int j=1;                    
	
		while(j<len[i])
		
		{         //Loop every digit in Array
			
			if(k[i][j-1]<=k[i][j]){ //Check if previous digit is higher than current digit
				j++;                
			
			    
			}
		
			else
			{                   
				
				k[i][j-1]--;        //Decrement previous digit
				int u=j;
				while(u<len[i])  //Loop to change rest of array to 9
					k[i][u++]=9;    
				j++;            
				i=0;                //Restart loop to confirm ascension order of digits
			}
		}
	
		i++;
	}	

	i=0;

	while(i<t)
	{                     //Display the tidy numbers
		
		printf("Case #%d: ",i+1);
		int j=0;
		
		while(j<len[i])
		{         //To avoid displaying if the number consists of 0 at the beginning
		
			if(k[i][j]==0)
			{         
			
				j++;
				continue;
			}
			
			printf("%d",k[i][j++]); //Display other digits
		}
	
		printf("\n");
		i++;
	}
	
	return 0;                     
}