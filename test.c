int main(void)
{
    FILE fd;

    char *line = NULL;
    size_t len = 0;
    ssize_t   read;

    fd = fopen("/my_GNL/test.txt");
    if (fd == NULL)
        exit(EXIT_FAILURE);
    
    while ((read = getline(&line, &len, fd)))
    {
        printf("asjkldjas");
    }

    free(line);
    exit(EXIT_SUCCESS);

}





// char **test;
// int  i;
// test = malloc(3 * sizeof(*lst));

// i = 0;
// while(i++ < 3)
// {
//     lst[i] = malloc(10);
//     fgets(test,1,stdin);
//     puts(test);

//     file
// }
// #include<unistd.h>
// #include<stdio.h>

// int main()
// {
//     FILE *fptr;
//     char str[100];

//     fptr = fopen("fgets.txt","r");
//     if (fptr == NULL)
//     {
//         perror(" Error Occured bulls !");
//         return -1;
//     }

//     else 
//     {
//         if (fgets(str,100,fptr) != NULL)
//         {
//             puts(str);
//         }
//         fclose(fptr);
//     }
//     return (0);
// }



// int main()
// {
//     char string[20];

//     fgets(string,20)
// }