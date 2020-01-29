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
  //  int count_l= count_letters(str);
  float L = (count_l/countword)*100;
  float S = (cs/countword)*100;
  int index = round(0.0588 * L - 0.296 * S - 15.8);
  if(index > 16)
  {
        printf("Grade 16+\n");
  }
  else if(index < 1)
  {
      printf("Before Grade 1\n");
  }
  else
  {
      printf("Grade %d\n",index);
  }



//    printf("%d\n",count_l);
//    printf("%d\n",countword);
 //   printf("%d\n",cs);
}

