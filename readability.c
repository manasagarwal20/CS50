#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>
#include<math.h>
int main()
{
    string str = get_string("Text: ");
    int n = strlen(str);
    int countword = 1 , cs = 0, count_l=0;
    for(int i = 0; i < n;i++)
    {
        if(str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            cs++;
        }
        else if(isblank(str[i]))
        {
            countword++;
        }
        else if(islower(str[i]) || isupper(str[i]))
        {
            count_l++;
        }
    }

  float L = count_l*100/countword;
  float S = cs*100/countword;
 // float L = ceilf(lw * 100) / 100;
 // float S = ceilf(sw * 100) / 100;
 float index1=0.0588 * L - 0.296 * S - 15.8;
 // int index =0.0588 * L - 0.296 * S - 15.8;
  //printf("%d",index);
 // printf("%f",index1);
  if(index1 > 16)
  {
        printf("Grade 16+\n");
  }
  else if(index1< 1)
  {
      printf("Before Grade 1\n");
  }
  else
  {
      printf("Grade %d\n",index1);
  }



  //printf("%d\n",count_l);
 //  printf("%d\n",countword);
  //  printf("%d\n",cs);
}