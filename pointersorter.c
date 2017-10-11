/*This Project is about a sorting a string using a pointer and dynamic memory malloc
  Also used a bubble sort to arrage in a descending alphabetic order.*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("Please enter Valid string .... Try Again with %s ValidString !! Good Bye .....",argv[0]);
		return 0;
	}
	int i = 0;
        //Find a String length and add with one for null
	int a = strlen(argv[1]) +1 ;
	char s[a];
        //Copy our command input string into char array which is we make here
	memcpy(s,argv[1],strlen(argv[1]));
	s[a]='\0';
	int strCnt = 0, j=0;
	int prev=0,end=0;
        //Print a original string which cpoied  by memcpy function from argv[1] to char s[a]
	printf("Original String Value - %s\n",s);
        //Check each character from original string that, is character is alphabetic or non-alphabetic
        //If character is non-alphabetic then number will increase in char array and looking for next character for alphabetic or non-alphabetic
        //If character is alphabetic then loop will break.
	for( i = 0 ; i < strlen(s) ; i++)
	{
		if(!((s[i] >= 97 && s[i] <= 122 ) || (s[i] >= 65 && s[i] <= 90)))
		{
			continue;	
		}
		else
		{
			break;
		}
	}
        //If we find a smae number in array as our string length that means if their is not alphabet then message will print as not valid string input.
	if(i == strlen(s))
	{
		printf("No Valid sting found for Sorting ! Please try again ..... Good Bye .....");
		return 0;
	}
        //Counting a valid world which is alphabetic removing with non-alphabetic character
	for(  ; i < strlen(s) ; )
	{
                //If find a alphabetic character then if will work and will increase for loop and will check for next character
                //If will work until not getting non-alphabetic character
		if((s[i] >= 97 && s[i] <= 122 ) || (s[i] >= 65 && s[i] <= 90))
		{
			i++;
			if(i>=strlen(s))
			{
				strCnt ++;
			}
			continue;
		}
                //Else will work when Non-alphabetic character is coming and count for a word until non-alphabetic charcter coming 
		else
		{
			if(i > 0 )
				strCnt ++;
                //After counting valid word for loop will check for next character if alphabetic will break loop and if non-alphabetic continue with this for loop
			
			for( j = i+1; j<strlen(s) ; j++)
			{
				if((s[j] >= 97 && s[j] <= 122 ) || (s[j] >= 65 && s[j] <= 90))
					break;
			}
                //initial j value into i for outer 'for loop' 
			i = j;
			
		}
	}
        //Print a valid word and create an Array of pointer 
	printf(" Number Of Valid Word Found : %d\n",strCnt);
	char *strPointer[strCnt];
	int counter=0;
        //Find a starting position of word and ending position of word and make a block (dynamic memory) using malloc same as word length
	for(i=0;i<strlen(s);)
	{
        //checking character is alphabetic then continue 
		if((s[i] >= 97 && s[i] <= 122 ) || (s[i] >= 65 && s[i] <= 90))
		{
			i++; end = i;
			if(i>=strlen(s))
			{
				
				int sizeOfstr = (end-prev+1);
				strPointer[counter] =  (char*) malloc(sizeOfstr);
				int k = 0; 
				for(j=prev;j<end;j++)
				{
					strPointer[counter][k]=s[j];
					k++;
				}
				strPointer[counter][sizeOfstr-1] ='\0';
			}
			continue;
		}
		else
		{
			//some position find a non-alphabetic then else will work and figur our starting and ending position of word
			int sizeOfstr = prev==0 ? (end + 1): (end-prev+1);
                        //make a block using dynamic memory malloc as size of word
			strPointer[counter] =  (char*) malloc(sizeOfstr);
			int k = 0; 
                        //In created block assign word in each raw same as total string and in column according to each word length
			for(j=prev;j<end;j++)
			{
				strPointer[counter][k]=s[j];
				k++;
			}
                        //At the end of each word assign null
			strPointer[counter][sizeOfstr-1] ='\0';
			counter ++;
			 			for( j = i+1; j<strlen(s) ; j++)
			{
				if((s[j] >= 97 && s[j] <= 122 ) || (s[j] >= 65 && s[j] <= 90))
					break;
			}
			prev = i =  j;
			
		}
	}
	//Print each word in a diffrent row and show what is stored in malloc
	//If first memory block is contain null then if statement will work and if not null then else will work
        //This is usefull because if user entered non-alphabetic character then this if statement will work and if user entered a string with alphabetic character then control will go in else part
     if(strPointer[0][0]=='\0')
     {
        printf("My Words Before Sorting (Memory of word assign with Malloc) is : \n");
        for(i=0;i<strCnt+1;i++)
	{
		printf("%s\n",strPointer[i]);
	}
        char* temp;
        //Swap a string using bubble sort and arrage in a descending alphabetic order
    for(i=0;i<strCnt-1;i++)
    {
        for(j=0;j<strCnt-i-1;j++)
        {
            if((strcmp(strPointer[j], strPointer[j+1]) > 0))
            {
                temp =  strPointer[j];
				strPointer[j] = strPointer[j+1];
				strPointer[j+1] = temp;   
            }
        }
    }
      printf("\nSorted String is :\n");
	for(i=0;i<=strCnt;i++)
	{
		printf("%s\n",strPointer[i]);
	}
   }  
     else
     {
        for(i=0;i<strCnt;i++)
	{
	     printf("%s\n",strPointer[i]);
	}
                
	//Create a pointer name with temp to point each string whihc is stored in malloc to swap it
	char* temp;
        //Swap a string using bubble sort and arrage in a descending alphabetic order
    for(i=0;i<strCnt-1;i++)
    {
        for(j=0;j<strCnt-i-1;j++)
        {
            if((strcmp(strPointer[j], strPointer[j+1]) > 0))
            {
                temp =  strPointer[j];
				strPointer[j] = strPointer[j+1];
				strPointer[j+1] = temp;   
            }
        }
    }
    printf("\nSorted String :\n");
        for(i=0;i<strCnt;i++)
	{
	     printf("%s\n",strPointer[i]);
	}
      
 }
 free(strPointer[counter]);
 return(0);
 

}        

 
	

