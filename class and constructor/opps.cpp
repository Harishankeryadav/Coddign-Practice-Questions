class student
{
private:
    int Id;

public:
    int roll_num;
    char name[20];

    int check(int passs, int b)
    {
        if (Id != 123)
        {
            return;
        }
        Id = b;
        return b;
    }
    void getdata(int a, char b[], int len)
    {
        roll_num = a;
        for (int i = 0; i < len; i++)
        {
            name[i] = b[i];
        }
    }
    void display(int len)
    {
        cout << "Id is " << Id << "\nRoll number is " << roll_num << "\nName is ";
        for (int i = 0; i < len; i++)
        {
            cout << name[i];
        }
    }
};