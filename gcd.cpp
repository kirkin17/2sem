bool NZER_N_B(int ykaz[], int b) { //N2, Автор - Ольга Валерьева
	for (int i = 0; i < b; i++) {
		if (ykaz[i] != 0)
			return 1; //число не равно нулю
		else
			return 0; //число равно нулю
	}
}

int GCF_NN_N(int a[],int an,int b[],int bn,int otv[]) //Прохоренко К.
{
    int* r; //ostatok
    int tmp;
    r = new int[an];
    while(NZER_N_B(b, bn))
    {
        //r = MOD_NN_N(a,an,b,bn);
        for (int i = 0; i < an; i++)
        {
            a[i] = tmp;
            a[i] = b[i];
            b[i] = tmp;
        }
        for (int i = 0; i < bn; i++)
        {
            b[i] = r[i];
        }
    }
    delete[] r;
    //вывод
    int* otv;
    otv = new int[an];
    for (int i = 0;i <= an; i++)
    {
    otv[i] = a[i];
    }
}
