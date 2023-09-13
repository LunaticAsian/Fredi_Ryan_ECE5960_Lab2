//Applies a function to the given data set and returns the data set after
//applying the function.
void map(int *input_list, int length, int (*func_ptr)(int))
{
    for(int i=0; i<length; i++)
    {
       (input_list[i]) = funct_ptr(input_list[i]);

    }
}