    int count = 0;
    while (true)
    {
        if (f % 10 == 0)
        {
            count++;
            f /= 10;
        }
        else
        {
            break;
        }
    }
    cout << count << endl;