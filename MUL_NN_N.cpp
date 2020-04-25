int MUL_NN_N(int* a, int an, int* b, int bn) //Прохоренко К.
{
    if (an > bn)
    {
        int otv[an];
        for (int i = 0; i < bn; i++)
        {
            otv[i] = ADD_NN_N(otv, an, MUL_Nk_N(MUL_ND_N(a, b[i]), bn - i - 1));
        }
    }
}
