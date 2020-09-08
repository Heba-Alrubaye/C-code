

#include <stdio.h>
#include "editor2.h"


int editor_count_lines( const char *buffer, int s)
{

 int count=0;
 char *p ;
 p=buffer;//put the pointer to the first address in buffer
 for (p;p<buffer+s;p++)
    {
  if(*p=='\n'){
   count++;
    }
 }
  return count;
}

int editor_search_multiple(const char *editing_buffer, int s, const char *sub, int *data, int d)
{
  char *p1, *p2, *p3;
  int i=0,j=0,flag=0;
  p1 = editing_buffer;//put p1 in the first address in buffer
  p2 = sub;//put p2 in the first address in sub
  for(i = 0; i<strlen(editing_buffer);i++)
  {
   if(*p1 == *p2)
      {
      p3 = p1;
   for(j = 0;j<strlen(sub);j++)
          {
     if(*p3 == *p2)
            {
      p3++;p2++;
            }
        else
         break;
          }
      p2 = sub;//put p2 in first address to the next appearance
     if(j == strlen(sub))
          {
        *data = i;//put the index in int array
         data++;//increament array
            }
         flag ++;
           }
         p1++;
           }
    return flag;
    if(flag==0)
      {
    printf("Substring NOT found");
      }
  }



