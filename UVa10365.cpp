#include <cstdio>

int sol[1000]={6,10,14,16,22,22,30,24,30,34,46,32,54,46,46,40,70,42,78,48,62,70,94,52,70,82,54,64,118,62,126,64,94,106,94,66,150,118,110,76,166,82,174,96,78,142,190,80,126,90,142,112,214,90,142,100,158,178,238,94,246,190,102,96,166,122,270,144,190,118,286,108,294,226,110,160,190,142,318,112,126,250,334,122,214,262,238,148,358,126,222,192,254,286,238,128,390,154,150,130,406,182,414,172,142,322,430,144,438,174,302,144,454,202,286,240,174,358,286,148,286,370,334,256,150,162,510,160,350,202,526,178,318,406,174,220,550,242,558,166,382,430,334,168,358,442,182,304,598,170,606,244,222,226,382,206,630,478,430,184,382,198,654,336,206,502,670,188,390,258,246,352,694,302,190,208,478,538,718,192,726,262,494,292,454,322,430,384,222,286,766,208,774,586,238,210,790,234,798,210,542,610,478,262,502,622,294,240,478,214,846,432,574,646,526,216,510,658,590,238,502,382,894,232,230,682,910,290,918,342,262,364,934,270,574,480,638,334,958,236,966,330,270,496,238,422,558,388,670,250,1006,240,574,766,302,256,1030,442,606,274,366,790,1054,268,646,370,718,544,1078,258,1086,304,302,826,270,346,1110,838,390,262,1126,482,1134,576,334,382,670,264,646,426,782,592,1174,266,718,460,318,898,670,280,702,910,814,336,742,342,1230,298,830,454,1246,308,1254,946,286,640,1270,542,718,288,862,442,718,288,310,982,878,508,766,302,1326,672,462,1006,814,292,1350,442,910,346,766,378,294,532,398,1042,1390,430,1398,310,366,328,1414,602,862,720,382,1078,1438,312,798,1090,374,342,886,622,1470,400,510,538,862,458,1494,486,350,580,838,318,1518,382,1022,1150,1534,320,334,1162,534,784,1558,346,862,322,1054,1186,958,336,1590,1198,422,340,1606,682,894,816,342,550,910,388,1638,594,1102,832,958,450,1006,376,1118,538,1678,344,1686,1270,582,652,390,722,990,864,430,622,1726,348,1734,586,494,880,958,742,1758,366,350,562,1774,542,1078,1342,1198,352,1798,370,1006,912,1214,1366,382,428,1830,1378,462,454,1846,370,1854,496,526,1402,1870,384,1086,678,1262,724,1054,802,430,430,654,1438,1918,376,1062,1450,502,418,1174,378,1950,748,1310,378,1966,598,1078,622,398,528,1150,842,1998,400,1342,1510,2014,382,1222,642,494,1024,2038,434,1182,384,510,1546,1246,626,1150,694,1390,418,2086,558,2094,1056,430,1582,1150,404,1150,762,726,474,1174,902,1294,820,1438,1618,406,408,2166,1630,1454,472,1318,422,2190,1104,750,430,1198,508,1278,1666,622,1120,2230,594,1230,412,542,1690,2254,682,1366,1702,414,868,2278,478,2286,478,1534,766,510,416,2310,714,1550,562,1342,982,1294,892,454,1762,2350,434,1278,846,1582,624,2374,438,478,1200,1598,742,2398,440,2406,802,822,1216,462,1022,2430,520,622,874,1342,480,2454,1846,686,442,2470,1042,2478,598,606,1870,1438,460,550,1882,598,1264,1366,446,2526,964,1694,1906,1534,766,462,798,870,448,2566,1082,2574,562,718,790,2590,450,1438,490,662,1312,2614,1102,1582,688,894,874,2638,472,2646,1990,622,1012,526,702,1438,1344,1790,958,1486,472,2694,2026,510,546,2710,1142,1566,522,1822,850,2734,528,1654,490,1838,720,1510,566,2766,1392,478,2086,1678,628,1510,2098,1870,480,2806,498,1518,480,782,2122,1630,850,2838,1014,966,1084,1534,526,526,1440,1918,2158,2878,484,1662,874,1934,1456,630,506,2910,502,486,1042,1582,878,2934,2206,518,616,1630,774,2958,706,686,982,2974,668,1798,2242,1014,598,1726,550,3006,784,2014,922,1822,510,3030,2278,710,574,3046,1282,1758,1536,566,2302,1678,512,3078,514,2062,1552,3094,810,670,1180,782,2338,1678,536,1726,942,750,532,1894,1322,3150,1584,2110,1126,1822,518,1734,2386,878,1600,3190,578,1726,520,1086,2410,1774,962,622,982,2158,1228,3238,522,3246,694,2174,1006,1966,572,1758,2458,542,778,3286,1382,3294,1252,590,1090,3310,624,3318,1182,2222,544,574,1402,2014,658,798,2518,3358,548,1798,2530,2254,1696,598,882,550,880,2270,610,1822,1018,3414,1126,622,1300,3430,574,3438,814,862,2590,3454,552,2086,2602,782,738,1918,698,1902,1324,1182,1042,670,1046,3510,2638,2350,556,3526,574,3534,682,974,2662,3550,788,2046,1266,558,1792,1918,1502,2158,576,814,2698,1918,560,1942,1110,902,1372,2182,1522,3630,1824,1230,582,3646,628,2014,2746,1006,1840,2110,618,3678,678,2462,2770,2014,586,790,2782,1254,760,3718,742,630,1872,2494,2806,654,586,3750,1234,2510,886,3766,1582,2014,976,606,1162,3790,1130,2070,670,2542,622,3814,990,2302,1920,878,2878,2206,592,2046,1162,1302,1936,2326,682,3870,594,862,1378,3886,594,2238,2926,670,1008,3910,1642,2158,616,1326,2950,3934,868,2374,1170,982,750,2110,598,3966,808,2654,1306,2398,1186,3990,2998,942,600};
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int s;
        scanf("%d",&s);
        printf("%d\n",sol[s-1]);
    }
}