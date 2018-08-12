#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

class Date {

    int day, mon, year;
    public:

    void SetValue(int d, int m, int y = 0)
    {
        day = d;
        mon = m;
        year = y;
    }

    bool operator <= (Date d)
    {
		int t = mon;

        if(day > d.day) t += 1;

        return d.mon - t < 0 ? false : true;
    }

    bool operator >= (Date d)
    {
		int t = mon;

        if(day > d.day) t += 1;

        return d.mon - t < 0 ? true : false;
    }

    Date operator = (Date d)
    {
        mon = d.mon;
        day = d.day;
        year = d.year;

        return (*this);
    }
};

class Zodiac
{
    public:
    Date start;
    Date end;
};

class ZodiacSign
{
    Zodiac aqua, pisces, aries, taurus, gemini, cancer, leo, virgo, libra, scorpio, sagit, capri;

    public:

    ZodiacSign()
    {
        aqua.start.SetValue(21, 1);
        aqua.end.SetValue(19, 2);
        pisces.start.SetValue(20, 2);
        pisces.end.SetValue(20, 3);
        aries.start.SetValue(21, 3);
        aries.end.SetValue(20, 4);
        taurus.start.SetValue(21, 4);
        taurus.end.SetValue(21, 5);
        gemini.start.SetValue(22, 5);
        gemini.end.SetValue(21, 6);
        cancer.start.SetValue(22, 6);
        cancer.end.SetValue(22, 7);
        leo.start.SetValue(23, 7);
        leo.end.SetValue(21, 8);
        virgo.start.SetValue(22, 8);
        virgo.end.SetValue(23, 9);
        libra.start.SetValue(24, 9);
        libra.end.SetValue(23, 10);
        scorpio.start.SetValue(24, 10);
        scorpio.end.SetValue(22, 11);
        sagit.start.SetValue(23, 11);
        sagit.end.SetValue(22, 12);
        capri.start.SetValue(23, 12);
        capri.end.SetValue(20, 1);
    }

    char *DetectZodiac(Date d)
    {
        if(d >= aqua.start && d <= aqua.end) return "aquarius";

        else if(d >= pisces.start && d <= pisces.end) return "pisces";

        else if(d >= aries.start && d <= aries.end) return "aries";

        else if(d >= taurus.start && d <= taurus.end) return "taurus";

        else if(d >= gemini.start && d <= gemini.end) return "gemini";

        else if(d >= cancer.start && d <= cancer.end) return "cancer";

        else if(d >= leo.start && d <= leo.end) return "leo";

        else if(d >= virgo.start && d <= virgo.end) return "virgo";

        else if(d >= libra.start && d <= libra.end) return "libra";

        else if(d >= scorpio.start && d <= scorpio.end) return "scorpio";

        else if(d >= sagit.start && d <= sagit.end) return "sagittarius";

        else return "capricorn";
    }
};

bool LeapYear(int y)
{
    if(y%4 != 0) return false;

    else if(y%100 != 0) return true;

    else if(y%400 == 0) return true;

    else return false;
}


int main()
{
    char in[10];
    int day, mon, year, bday, bmon, byear, t, i, j, k, ycount, temp;
    int DaysInMonth[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date result;
    ZodiacSign z;

    scanf("%d",&t);
    getchar();

    for(i = 1; i <= t; i++)
    {
        gets(in);

        k = 280;
        ycount = 0;

        mon = (in[0] - 48) * 10 + in[1] - 48;

        day = (in[2] - 48) * 10 + in[3] - 48;

        year = atoi(&in[4]);

        DaysInMonth[1] = LeapYear(year) ? 29 : 28;

        k -= DaysInMonth[mon - 1] - day + 1;

        j = mon;

        while(k >= 31)
        {
            if(j > 11) 
			{
				j = 0;
				ycount++;
				DaysInMonth[1] = LeapYear(year + ycount) ? 29 : 28;
			}

            k -= DaysInMonth[j++];
        }

        bday = k > 0 ? k + 1 : 1;

		temp = j + 1;

		if(temp > 12)
		{
			temp = temp - 12;
			ycount++;
		}

        bmon = temp;

        byear = year + ycount;

        result.SetValue(bday, bmon, byear);

        printf("%d %02d/%02d/%04d %s\n", i, bmon, bday, byear, z.DetectZodiac(result));
    }
    return 0;
}
