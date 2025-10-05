int *decrypt(int *code, int codeSize, int k, int *returnSize)
{
    *returnSize = codeSize;
    int *answer = (int *)malloc(sizeof(int) * codeSize);
    for (int i = 0; i < codeSize; i++)
    {
        answer[i] = 0;
    }

    if (k > 0)
    {
        for (int i = 0; i < codeSize; i++)
        {
            int a = (i + 1) % codeSize;
            int b = (i + k + 1) % codeSize;
            int index = a;
            while (index != b)
            {
                answer[i] += code[index];
                index = (index + 1) % codeSize; // move forward
            }
        }
    }
    else if (k < 0)
    {
        int m = -k;
        for (int i = 0; i < codeSize; i++)
        {
            int a = (i - 1 + codeSize) % codeSize;
            int b = (i - m - 1 + codeSize) % codeSize; // FIXED
            int index = a;
            while (index != b)
            {
                answer[i] += code[index];
                index = (index - 1 + codeSize) % codeSize;
            }
        }
    }

    return answer;
}
