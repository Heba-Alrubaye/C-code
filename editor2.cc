/**
 * editor2.cc
 *
 *
 * Student ID:300505480
 * Name:Heba AL-Rubaye
 */

#include <iostream>
#include "editor2.hh"
#include <ctype.h>
#include <string>

using namespace editor2;


 int EditorUtilities ::countWords( char *buffer, int s)
{
  char *p;
  int numwords=0;
  int len=0;
  p = buffer;
   for (p;p<buffer+s;p++){
    if(*p == ' '||*p=='\t'||*p=='\n'||*p=='\v'||*p=='\f'||*p=='\r'){
     len=0;
    }
    else if (++len==1){
     numwords++;
    }
  }
  return numwords;

}

 int EditorUtilities::searchMultipleNoCase(const char *buffer, int s,const string *sub,int *data, int d)
{

    char buffercpy[s];
    char *p1, *p2, *p3;
    int i=0,j=0,flag=0;
    char *sPtr;

    for (int i=0;i<s;i++){
     buffercpy[i]=buffer[i];//copy buffer contant to buffercpy
    }
    sPtr = buffercpy;
    while(*sPtr){
    if (isupper(*sPtr )){ // if character is upper
      *sPtr = tolower( *sPtr);  // convert to lower
    }
    ++sPtr;  // move sPtr to next character in string
    }
   p1= buffercpy;
   p2 = sub;
   for(i = 0; i<strlen(buffercpy);i++)
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

         p2 = sub;
    if(j == strlen(sub))
          {
         *data = i;
          data++;
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

