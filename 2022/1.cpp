#include <iostream>

static const uint64_t input[] =
{
13399  ,
13677  ,
11945  ,
9861   ,
6484   ,
4257   ,
0      ,
6616   ,
7349   ,
7758   ,
1591   ,
6068   ,
9217   ,
6924   ,
6766   ,
0      ,
10040  ,
9088   ,
11305  ,
5867   ,
10766  ,
9996   ,
11092  ,
0      ,
1320   ,
4921   ,
2338   ,
1351   ,
3462   ,
5916   ,
3124   ,
1416   ,
3655   ,
4886   ,
1135   ,
5171   ,
5020   ,
5099   ,
4785   ,
0      ,
1702   ,
5083   ,
3852   ,
3361   ,
2505   ,
3767   ,
1069   ,
3564   ,
3189   ,
5950   ,
2250   ,
2053   ,
1639   ,
1430   ,
4586   ,
0      ,
4135   ,
7033   ,
4649   ,
3126   ,
1136   ,
1435   ,
3825   ,
2205   ,
1259   ,
5473   ,
1803   ,
6406   ,
0      ,
2466   ,
30094  ,
0      ,
3122   ,
2983   ,
5988   ,
4214   ,
5278   ,
1974   ,
7109   ,
2419   ,
3777   ,
8299   ,
0      ,
10191  ,
6122   ,
7298   ,
7855   ,
8666   ,
4777   ,
6833   ,
8862   ,
0      ,
6100   ,
5332   ,
1908   ,
2796   ,
1818   ,
4657   ,
1650   ,
5560   ,
8447   ,
8619   ,
0      ,
9547   ,
1354   ,
1561   ,
2943   ,
2547   ,
9313   ,
9649   ,
0      ,
1323   ,
1200   ,
2514   ,
1412   ,
1381   ,
2310   ,
6201   ,
3257   ,
1747   ,
1295   ,
2507   ,
5594   ,
6010   ,
3422   ,
0      ,
1995   ,
3514   ,
8434   ,
1625   ,
2257   ,
3551   ,
6881   ,
0      ,
12256  ,
1829   ,
11123  ,
18829  ,
0      ,
11790  ,
1786   ,
13935  ,
10088  ,
3486   ,
2981   ,
0      ,
5046   ,
1306   ,
4328   ,
7100   ,
6000   ,
6287   ,
3624   ,
6521   ,
3952   ,
3107   ,
3846   ,
2762   ,
0      ,
21245  ,
8245   ,
0      ,
14395  ,
8107   ,
4730   ,
15633  ,
0      ,
1648   ,
2062   ,
4574   ,
2446   ,
5471   ,
3973   ,
5319   ,
1370   ,
4113   ,
1784   ,
5596   ,
3336   ,
4557   ,
5690   ,
4259   ,
0      ,
9587   ,
3062   ,
5611   ,
10487  ,
2759   ,
0      ,
69383  ,
0      ,
4683   ,
4950   ,
1709   ,
6063   ,
2338   ,
4583   ,
4749   ,
6431   ,
4269   ,
1193   ,
6012   ,
5525   ,
2704   ,
2462   ,
0      ,
1627   ,
7447   ,
8071   ,
6915   ,
7021   ,
7778   ,
6861   ,
4647   ,
4006   ,
3953   ,
0      ,
1866   ,
9649   ,
0      ,
10777  ,
2179   ,
5406   ,
1772   ,
3472   ,
8632   ,
0      ,
5609   ,
7270   ,
9122   ,
4723   ,
8155   ,
3113   ,
6348   ,
6468   ,
0      ,
5029   ,
3416   ,
7531   ,
8764   ,
9506   ,
2104   ,
7992   ,
9329   ,
2530   ,
0      ,
36312  ,
11422  ,
0      ,
5790   ,
3655   ,
2172   ,
6254   ,
11150  ,
1624   ,
1014   ,
0      ,
6789   ,
2406   ,
6639   ,
4712   ,
4219   ,
2880   ,
5426   ,
6339   ,
1460   ,
1188   ,
5297   ,
4006   ,
2118   ,
0      ,
3351   ,
1304   ,
5559   ,
3742   ,
4749   ,
3648   ,
5671   ,
4213   ,
4047   ,
1243   ,
1674   ,
1943   ,
4974   ,
3576   ,
2816   ,
0      ,
4949   ,
6136   ,
6448   ,
1652   ,
2764   ,
6968   ,
5423   ,
3887   ,
6863   ,
3628   ,
4183   ,
0      ,
2857   ,
5671   ,
3486   ,
4910   ,
2913   ,
6441   ,
5863   ,
3306   ,
6473   ,
2428   ,
2509   ,
1188   ,
3289   ,
4418   ,
0      ,
2509   ,
8521   ,
2190   ,
8998   ,
7303   ,
5667   ,
0      ,
3486   ,
8687   ,
2976   ,
5155   ,
1013   ,
9599   ,
8559   ,
0      ,
9018   ,
10121  ,
9235   ,
5724   ,
10350  ,
0      ,
2389   ,
9061   ,
8031   ,
6711   ,
6046   ,
3058   ,
1890   ,
6047   ,
7664   ,
0      ,
1286   ,
1915   ,
6597   ,
0      ,
6012   ,
6146   ,
9585   ,
12335  ,
3708   ,
7652   ,
0      ,
4501   ,
3470   ,
3260   ,
6125   ,
3718   ,
3379   ,
5225   ,
4673   ,
5943   ,
1010   ,
2057   ,
3389   ,
2009   ,
0      ,
4640   ,
2437   ,
4673   ,
2628   ,
5333   ,
7027   ,
8001   ,
7678   ,
4903   ,
7670   ,
1898   ,
0      ,
47670  ,
0      ,
3884   ,
23968  ,
11759  ,
0      ,
4154   ,
5214   ,
2482   ,
4226   ,
3115   ,
2272   ,
1209   ,
2525   ,
2985   ,
3399   ,
3140   ,
4385   ,
1291   ,
3911   ,
0      ,
15947  ,
12913  ,
12250  ,
0      ,
7196   ,
3574   ,
6499   ,
2127   ,
4295   ,
6611   ,
3292   ,
6542   ,
1280   ,
4757   ,
6430   ,
7364   ,
0      ,
36842  ,
21414  ,
0      ,
15106  ,
26273  ,
0      ,
2751   ,
1089   ,
2380   ,
3818   ,
1737   ,
1247   ,
3897   ,
1466   ,
3772   ,
3890   ,
4032   ,
6280   ,
5202   ,
3879   ,
0      ,
4406   ,
7919   ,
7174   ,
7182   ,
2076   ,
4281   ,
9077   ,
1814   ,
5768   ,
0      ,
4183   ,
5280   ,
5978   ,
3859   ,
1915   ,
2297   ,
1478   ,
3486   ,
2438   ,
4829   ,
2279   ,
5057   ,
2625   ,
5242   ,
2532   ,
0      ,
1699   ,
2463   ,
5703   ,
5850   ,
6899   ,
2344   ,
7855   ,
6715   ,
6421   ,
5289   ,
3702   ,
0      ,
11196  ,
4585   ,
9888   ,
10474  ,
10927  ,
9486   ,
1240   ,
0      ,
9145   ,
35500  ,
0      ,
9017   ,
8861   ,
1486   ,
5209   ,
9027   ,
7222   ,
8914   ,
8981   ,
0      ,
10200  ,
6668   ,
9301   ,
4127   ,
9401   ,
5308   ,
7425   ,
4684   ,
0      ,
7333   ,
10840  ,
14603  ,
10690  ,
0      ,
15280  ,
12623  ,
0      ,
2628   ,
4448   ,
6702   ,
5674   ,
4786   ,
1955   ,
5817   ,
7391   ,
0      ,
2930   ,
5391   ,
1057   ,
5093   ,
9249   ,
5111   ,
8526   ,
0      ,
11978  ,
1172   ,
12728  ,
10126  ,
14320  ,
0      ,
9024   ,
10561  ,
11219  ,
10949  ,
9775   ,
1630   ,
5280   ,
0      ,
2785   ,
6174   ,
1854   ,
1905   ,
6071   ,
2125   ,
5350   ,
1186   ,
3905   ,
6166   ,
2533   ,
4059   ,
6731   ,
0      ,
9855   ,
3487   ,
3393   ,
1922   ,
3413   ,
10109  ,
5879   ,
1927   ,
0      ,
24634  ,
17427  ,
0      ,
6916   ,
5891   ,
4324   ,
4270   ,
1627   ,
3428   ,
3616   ,
7358   ,
0      ,
1720   ,
7552   ,
2489   ,
7386   ,
2502   ,
5020   ,
8134   ,
6329   ,
1752   ,
3651   ,
0      ,
2666   ,
4269   ,
5480   ,
3812   ,
1161   ,
4880   ,
2090   ,
1374   ,
4834   ,
4310   ,
0      ,
7381   ,
7578   ,
10690  ,
9863   ,
0      ,
4168   ,
6628   ,
8779   ,
4512   ,
9607   ,
13236  ,
0      ,
8983   ,
7035   ,
0      ,
5321   ,
6790   ,
7229   ,
4435   ,
4513   ,
1969   ,
4220   ,
6666   ,
1310   ,
5702   ,
2815   ,
3337   ,
0      ,
8165   ,
8740   ,
12582  ,
7713   ,
0      ,
6807   ,
7574   ,
2110   ,
8248   ,
3745   ,
8562   ,
4020   ,
4169   ,
1765   ,
4891   ,
0      ,
17008  ,
3541   ,
13728  ,
10051  ,
0      ,
9546   ,
3634   ,
11918  ,
10456  ,
6942   ,
8063   ,
0      ,
8529   ,
13227  ,
7794   ,
1031   ,
4572   ,
11405  ,
0      ,
4153   ,
6659   ,
22281  ,
0      ,
11515  ,
2370   ,
0      ,
5548   ,
1377   ,
1211   ,
6916   ,
1775   ,
6326   ,
4643   ,
5420   ,
2426   ,
1870   ,
6828   ,
4954   ,
4020   ,
0      ,
17677  ,
4591   ,
11515  ,
0      ,
27640  ,
0      ,
1151   ,
2701   ,
3155   ,
4768   ,
5921   ,
1581   ,
2137   ,
4733   ,
5815   ,
4884   ,
2760   ,
2365   ,
5740   ,
5709   ,
4972   ,
0      ,
8728   ,
6887   ,
3823   ,
2605   ,
5475   ,
3860   ,
6041   ,
6430   ,
7326   ,
1646   ,
0      ,
4335   ,
2773   ,
5938   ,
2121   ,
4260   ,
6369   ,
6997   ,
3884   ,
4772   ,
1516   ,
2081   ,
0      ,
6213   ,
8805   ,
7238   ,
5345   ,
1192   ,
4939   ,
2806   ,
7313   ,
0      ,
4753   ,
6108   ,
7647   ,
3770   ,
1151   ,
3026   ,
7908   ,
4970   ,
7434   ,
7037   ,
2897   ,
0      ,
5302   ,
9296   ,
11044  ,
7970   ,
13693  ,
0      ,
7211   ,
1990   ,
3859   ,
6882   ,
3344   ,
4598   ,
2233   ,
2877   ,
2708   ,
3417   ,
6936   ,
2253   ,
0      ,
6373   ,
6764   ,
3884   ,
7391   ,
5533   ,
1137   ,
2496   ,
7434   ,
5125   ,
3866   ,
1692   ,
1925   ,
0      ,
4935   ,
6462   ,
6626   ,
2070   ,
1478   ,
6686   ,
4058   ,
2785   ,
1455   ,
3868   ,
0      ,
9644   ,
4807   ,
8557   ,
9675   ,
3245   ,
8615   ,
2544   ,
0      ,
4673   ,
6408   ,
7255   ,
2955   ,
8642   ,
8242   ,
6319   ,
4034   ,
1881   ,
0      ,
4863   ,
3401   ,
1929   ,
7349   ,
2101   ,
3531   ,
6030   ,
1829   ,
2810   ,
6337   ,
2740   ,
3333   ,
0      ,
2544   ,
3546   ,
4223   ,
3984   ,
5038   ,
3259   ,
3726   ,
6850   ,
6201   ,
2285   ,
2743   ,
2805   ,
0      ,
2831   ,
5952   ,
4857   ,
5209   ,
3788   ,
7752   ,
1897   ,
5149   ,
1566   ,
5627   ,
1744   ,
0      ,
13339  ,
25673  ,
0      ,
6041   ,
5270   ,
3150   ,
5930   ,
3880   ,
7634   ,
4617   ,
3736   ,
1598   ,
3545   ,
0      ,
12877  ,
3897   ,
16515  ,
0      ,
8603   ,
11316  ,
15009  ,
14921  ,
11366  ,
0      ,
29818  ,
0      ,
6943   ,
6084   ,
3655   ,
2357   ,
6786   ,
4932   ,
4144   ,
1856   ,
6735   ,
5396   ,
1969   ,
3564   ,
6248   ,
0      ,
21889  ,
22636  ,
7127   ,
0      ,
5436   ,
2129   ,
3427   ,
4028   ,
1375   ,
5428   ,
3513   ,
2017   ,
2241   ,
2350   ,
4854   ,
4469   ,
6433   ,
4620   ,
0      ,
8399   ,
5055   ,
7440   ,
1229   ,
5012   ,
8573   ,
8127   ,
0      ,
6239   ,
5302   ,
1102   ,
3281   ,
5757   ,
5335   ,
4485   ,
4455   ,
4786   ,
3304   ,
2231   ,
1380   ,
3369   ,
1580   ,
0      ,
7307   ,
4830   ,
3948   ,
3827   ,
1887   ,
4315   ,
7452   ,
4969   ,
5245   ,
4550   ,
7218   ,
2174   ,
0      ,
7447   ,
1081   ,
4264   ,
7055   ,
3586   ,
5229   ,
7455   ,
6934   ,
6149   ,
3960   ,
0      ,
15053  ,
15764  ,
7760   ,
4107   ,
0      ,
3289   ,
4370   ,
9653   ,
10131  ,
7939   ,
7051   ,
9606   ,
8231   ,
0      ,
9300   ,
8135   ,
7629   ,
9080   ,
3896   ,
1975   ,
8696   ,
1182   ,
0      ,
3985   ,
4089   ,
4921   ,
5219   ,
6964   ,
6433   ,
6509   ,
4185   ,
1005   ,
1026   ,
7124   ,
2661   ,
0      ,
6051   ,
14787  ,
7797   ,
15612  ,
10055  ,
0      ,
4012   ,
4017   ,
2304   ,
2605   ,
5743   ,
1403   ,
1125   ,
8710   ,
7720   ,
8718   ,
0      ,
6678   ,
4366   ,
4875   ,
6185   ,
3490   ,
1883   ,
3966   ,
1955   ,
6868   ,
2049   ,
3847   ,
2604   ,
5276   ,
0      ,
3260   ,
5099   ,
1168   ,
4772   ,
6425   ,
2118   ,
4669   ,
2970   ,
2545   ,
2870   ,
2477   ,
3117   ,
5656   ,
1638   ,
0      ,
3476   ,
16997  ,
3993   ,
0      ,
1125   ,
1370   ,
4944   ,
8135   ,
3965   ,
4389   ,
9460   ,
3168   ,
1910   ,
0      ,
2953   ,
1838   ,
3452   ,
7390   ,
5918   ,
6095   ,
6666   ,
7163   ,
6031   ,
3723   ,
0      ,
7718   ,
1141   ,
1675   ,
8446   ,
5294   ,
0      ,
5377   ,
6680   ,
7310   ,
6375   ,
5910   ,
2649   ,
9240   ,
0      ,
7748   ,
6530   ,
10511  ,
12346  ,
9936   ,
1147   ,
0      ,
5383   ,
2504   ,
2837   ,
4482   ,
2089   ,
5223   ,
5901   ,
2419   ,
2722   ,
1275   ,
5022   ,
4864   ,
1186   ,
3471   ,
0      ,
1424   ,
4107   ,
5138   ,
6033   ,
1772   ,
4181   ,
3155   ,
1846   ,
6531   ,
6357   ,
3427   ,
6064   ,
0      ,
6840   ,
12459  ,
10532  ,
13685  ,
7208   ,
0      ,
10299  ,
9237   ,
1345   ,
5427   ,
7106   ,
2016   ,
1041   ,
7238   ,
0      ,
3221   ,
8456   ,
3885   ,
7423   ,
6113   ,
4968   ,
9018   ,
5032   ,
6529   ,
0      ,
33934  ,
7098   ,
0      ,
7112   ,
24553  ,
0      ,
11885  ,
11364  ,
7529   ,
7103   ,
8676   ,
6579   ,
3688   ,
0      ,
25617  ,
10321  ,
0      ,
4047   ,
3253   ,
1844   ,
2799   ,
1668   ,
2965   ,
4873   ,
6097   ,
6295   ,
6440   ,
5524   ,
2244   ,
5140   ,
1709   ,
0      ,
2615   ,
2931   ,
3283   ,
6939   ,
4277   ,
2219   ,
6990   ,
6804   ,
6249   ,
5762   ,
1461   ,
1084   ,
0      ,
32423  ,
27423  ,
0      ,
14517  ,
13142  ,
10941  ,
19562  ,
0      ,
5455   ,
1050   ,
5920   ,
5358   ,
1310   ,
4716   ,
3229   ,
1832   ,
4729   ,
1023   ,
3679   ,
2541   ,
3880   ,
1570   ,
3417   ,
0      ,
16181  ,
14620  ,
16387  ,
14881  ,
13553  ,
0      ,
5812   ,
2876   ,
4562   ,
3768   ,
3935   ,
5042   ,
7771   ,
6679   ,
7969   ,
4621   ,
7996   ,
0      ,
21785  ,
0      ,
2879   ,
3483   ,
14624  ,
15533  ,
0      ,
3101   ,
1823   ,
3319   ,
1134   ,
5269   ,
2554   ,
1437   ,
6490   ,
1859   ,
5525   ,
1183   ,
7439   ,
0      ,
5209   ,
6916   ,
5888   ,
1564   ,
5739   ,
6298   ,
4936   ,
5691   ,
3928   ,
4678   ,
4320   ,
1645   ,
0      ,
2079   ,
4168   ,
3031   ,
2456   ,
5446   ,
2338   ,
1479   ,
2522   ,
2715   ,
1725   ,
1596   ,
5845   ,
5028   ,
1472   ,
4262   ,
0      ,
26049  ,
35356  ,
0      ,
7064   ,
5479   ,
7564   ,
6219   ,
1482   ,
3370   ,
2480   ,
6777   ,
2460   ,
4600   ,
1526   ,
0      ,
58980  ,
0      ,
6251   ,
4189   ,
4778   ,
4814   ,
5817   ,
1498   ,
1721   ,
2071   ,
1297   ,
3638   ,
4299   ,
6097   ,
1840   ,
5523   ,
0      ,
6232   ,
2066   ,
5782   ,
6549   ,
2873   ,
3707   ,
1461   ,
3857   ,
7477   ,
0      ,
10217  ,
4464   ,
7487   ,
5948   ,
2641   ,
6622   ,
5401   ,
3488   ,
0      ,
39956  ,
0      ,
4731   ,
4717   ,
3048   ,
1349   ,
1819   ,
2364   ,
3993   ,
4572   ,
4118   ,
3673   ,
2932   ,
3557   ,
1818   ,
4040   ,
1809   ,
0      ,
7128   ,
2747   ,
10012  ,
9847   ,
11104  ,
0      ,
5461   ,
8787   ,
11013  ,
2435   ,
7903   ,
6058   ,
9698   ,
0      ,
6006   ,
2230   ,
1588   ,
3453   ,
1979   ,
4157   ,
4378   ,
2516   ,
3326   ,
4336   ,
5900   ,
4330   ,
3758   ,
1876   ,
0      ,
6303   ,
1498   ,
5453   ,
3870   ,
6501   ,
7204   ,
7517   ,
4713   ,
6341   ,
2922   ,
0      ,
7334   ,
4897   ,
4402   ,
10953  ,
11054  ,
10268  ,
9793   ,
0      ,
4308   ,
2009   ,
2882   ,
6288   ,
2014   ,
6973   ,
5200   ,
5629   ,
1899   ,
5681   ,
4634   ,
2955   ,
0      ,
64804  ,
0      ,
2857   ,
3134   ,
5935   ,
4192   ,
3976   ,
3585   ,
2199   ,
4054   ,
4975   ,
3372   ,
1872   ,
4617   ,
1449   ,
2854   ,
1817   ,
0      ,
25804  ,
30702  ,
0      ,
3722   ,
15874  ,
21786  ,
0      ,
3532   ,
2397   ,
6481   ,
6355   ,
3696   ,
6585   ,
6740   ,
6653   ,
1094   ,
3088   ,
3531   ,
0      ,
5927   ,
6252   ,
1132   ,
5256   ,
2514   ,
6460   ,
3890   ,
5604   ,
5112   ,
2472   ,
2584   ,
6801   ,
6849   ,
0      ,
10325  ,
4424   ,
2601   ,
3731   ,
1337   ,
2744   ,
9597   ,
7075   ,
0      ,
8526   ,
2577   ,
13053  ,
18958  ,
0      ,
4560   ,
2559   ,
1153   ,
4408   ,
4988   ,
5067   ,
5099   ,
2303   ,
5451   ,
5604   ,
2316   ,
3957   ,
4706   ,
1424   ,
0      ,
9698   ,
14099  ,
2964   ,
11611  ,
6559   ,
0      ,
33997  ,
17918  ,
0      ,
3078   ,
10535  ,
5480   ,
8484   ,
0      ,
9256   ,
15323  ,
22521  ,
0      ,
6174   ,
1290   ,
0      ,
2650   ,
3963   ,
5043   ,
2957   ,
2425   ,
1608   ,
5621   ,
3002   ,
4820   ,
7220   ,
5857   ,
2229   ,
0      ,
1787   ,
9599   ,
6118   ,
5536   ,
10061  ,
4869   ,
7507   ,
10471  ,
0      ,
6642   ,
9476   ,
8827   ,
1134   ,
8236   ,
3198   ,
9233   ,
1183   ,
2111   ,
0      ,
2519   ,
13308  ,
4466   ,
7787   ,
11427  ,
10148  ,
0      ,
2051   ,
8362   ,
3560   ,
8921   ,
11983  ,
10986  ,
0      ,
17512  ,
16150  ,
16427  ,
4874   ,
0      ,
1907   ,
4166   ,
3506   ,
3711   ,
6450   ,
1079   ,
6463   ,
1540   ,
3003   ,
1552   ,
2365   ,
2677   ,
6334   ,
0      ,
5683   ,
5447   ,
7822   ,
1999   ,
5990   ,
3230   ,
6628   ,
8877   ,
0      ,
4759   ,
3993   ,
1209   ,
6762   ,
3003   ,
6471   ,
4859   ,
4760   ,
1740   ,
4548   ,
2611   ,
4958   ,
2878   ,
0      ,
3511   ,
5142   ,
2343   ,
6232   ,
1655   ,
7021   ,
1258   ,
6838   ,
6246   ,
3258   ,
2833   ,
5692   ,
0      ,
14573  ,
6206   ,
7184   ,
0      ,
12569  ,
12014  ,
8487   ,
0      ,
5170   ,
3993   ,
2230   ,
8236   ,
1047   ,
2335   ,
7772   ,
10473  ,
0      ,
6108   ,
6449   ,
1413   ,
6964   ,
3161   ,
6252   ,
2130   ,
2719   ,
5420   ,
7277   ,
0      ,
1583   ,
8946   ,
17657  ,
13041  ,
0      ,
4422   ,
2025   ,
6174   ,
5449   ,
3686   ,
2354   ,
1209   ,
4111   ,
4326   ,
5606   ,
2071   ,
4023   ,
2194   ,
1317   ,
0      ,
4962   ,
7063   ,
5352   ,
4226   ,
2665   ,
3288   ,
6487   ,
4746   ,
1582   ,
3126   ,
5662   ,
6864   ,
0      ,
19194  ,
18115  ,
9773   ,
13571  ,
0      ,
3436   ,
3246   ,
1528   ,
2100   ,
5781   ,
2942   ,
1985   ,
3354   ,
5996   ,
6033   ,
4556   ,
4816   ,
3445   ,
5674   ,
0      ,
7953   ,
1275   ,
11734  ,
3295   ,
8462   ,
12028  ,
10019  ,
0      ,
1766   ,
2223   ,
3111   ,
3804   ,
3618   ,
4227   ,
2342   ,
2235   ,
3909   ,
2615   ,
4193   ,
2296   ,
0      ,
2843   ,
1898   ,
4501   ,
3483   ,
6084   ,
5807   ,
2422   ,
5786   ,
4145   ,
2572   ,
5803   ,
2697   ,
3218   ,
2038   ,
0      ,
11871  ,
1625   ,
13110  ,
12275  ,
12224  ,
3092   ,
0      ,
8174   ,
8230   ,
16977  ,
0      ,
4156   ,
3989   ,
4409   ,
2022   ,
4922   ,
5252   ,
3871   ,
5072   ,
4632   ,
5995   ,
1056   ,
4716   ,
3767   ,
5414   ,
1228   ,
0      ,
1282   ,
6053   ,
3736   ,
2202   ,
10695  ,
6392   ,
1384   ,
7369   ,
0      ,
28681  ,
29246  ,
0      ,
15208  ,
21904  ,
5766   ,
0      ,
46708  ,
0      ,
1735   ,
2394   ,
6503   ,
2545   ,
5642   ,
1806   ,
1340   ,
4804   ,
5163   ,
2480   ,
1842   ,
5795   ,
6230   ,
0      ,
5446   ,
4579   ,
4336   ,
1438   ,
3998   ,
2294   ,
3765   ,
5777   ,
4731   ,
1789   ,
3080   ,
5658   ,
6020   ,
2542   ,
3306   ,
0      ,
11770  ,
7451   ,
8351   ,
7333   ,
0      ,
25818  ,
0      ,
23933  ,
30654  ,
0      ,
8503   ,
3608   ,
18443  ,
0      ,
1571   ,
2813   ,
4847   ,
5863   ,
3118   ,
5888   ,
5529   ,
2732   ,
3260   ,
6378   ,
2254   ,
5451   ,
3926   ,
1217   ,
0      ,
5575   ,
12012  ,
8351   ,
6175   ,
4427   ,
5625   ,
9866   ,
0      ,
5468   ,
12325  ,
21005  ,
0      ,
5021   ,
3035   ,
3699   ,
1104   ,
6148   ,
6925   ,
6800   ,
4144   ,
4039   ,
5334   ,
3422   ,
3349   ,
2141   ,
0      ,
18504  ,
6184   ,
17915  ,
17015  ,
0      ,
2611   ,
3005   ,
2768   ,
2554   ,
5186   ,
5515   ,
4370   ,
4778   ,
2033   ,
4594   ,
4747   ,
5050   ,
6011   ,
1241   ,
3687   ,
0      ,
3572   ,
2053   ,
3035   ,
1019   ,
4649   ,
6236   ,
3675   ,
1697   ,
1756   ,
1384   ,
6392   ,
5508   ,
4879   ,
2579   ,
0      ,
17516  ,
1817   ,
4564   ,
0      ,
13428  ,
11868  ,
0      ,
2268   ,
3943   ,
1945   ,
4773   ,
1588   ,
3347   ,
2407   ,
5519   ,
4959   ,
2050   ,
1151   ,
5578   ,
3798   ,
3568   ,
0      ,
13729  ,
0      ,
2625   ,
13582  ,
7466   ,
6119   ,
6529   ,
8200   ,
0      ,
5149   ,
1177   ,
5792   ,
7468   ,
5574   ,
6245   ,
5567   ,
2265   ,
4336   ,
7321   ,
1343   ,
5623   ,
0      ,
3722   ,
8530   ,
2506   ,
5780   ,
5469   ,
6498   ,
7749   ,
2505   ,
0      ,
22983  ,
5225   ,
23416  ,
0      ,
12172  ,
0      ,
7005   ,
2913   ,
5003   ,
4441   ,
8602   ,
4818   ,
4073   ,
7066   ,
0      ,
2419   ,
3295   ,
4377   ,
5033   ,
4805   ,
3757   ,
1084   ,
4820   ,
2652   ,
4324   ,
3036   ,
4980   ,
1027   ,
0      ,
4367   ,
1801   ,
6250   ,
7051   ,
3410   ,
5676   ,
3559   ,
3589   ,
5903   ,
4154   ,
1524   ,
5197   ,
0      ,
6557   ,
4333   ,
4119   ,
5285   ,
4462   ,
6582   ,
6615   ,
5425   ,
6027   ,
0      ,
2623   ,
3519   ,
4234   ,
2637   ,
3220   ,
2879   ,
3305   ,
4309   ,
2591   ,
4333   ,
1030   ,
2778   ,
2065   ,
6071   ,
2426   ,
0      ,
8003   ,
2935   ,
0      ,
16146  ,
2907   ,
25872  ,
0      ,
2523   ,
4191   ,
3738   ,
5966   ,
3177   ,
4487   ,
4176   ,
4140   ,
3472   ,
1368   ,
3634   ,
4151   ,
3101   ,
3554   ,
1097   ,
0      ,
8706   ,
7566   ,
2050   ,
5536   ,
1457   ,
3515   ,
4303   ,
9118   ,
0      ,
2406   ,
1427   ,
5485   ,
14192  ,
0      ,
6581   ,
5469   ,
6933   ,
5186   ,
4634   ,
2457   ,
8450   ,
0      ,
6198   ,
10223  ,
9913   ,
1278   ,
10083  ,
10253  ,
8975   ,
8519   ,
0      ,
54888  ,
0      ,
1972   ,
4402   ,
4773   ,
5630   ,
5896   ,
6420   ,
1553   ,
4579   ,
1803   ,
1853   ,
4043   ,
5563   ,
2463   ,
0      ,
5240   ,
4200   ,
2061   ,
3277   ,
1346   ,
2627   ,
2714   ,
4837   ,
4338   ,
2206   ,
2051   ,
5209   ,
1106   ,
4793   ,
3229   ,
0      ,
6183   ,
4027   ,
4577   ,
4944   ,
1637   ,
4339   ,
2064   ,
4443   ,
1125   ,
2905   ,
2998   ,
5512   ,
6309   ,
4497   ,
0      ,
6302   ,
5477   ,
3874   ,
7152   ,
4289   ,
1502   ,
6993   ,
1968   ,
8201   ,
3361   ,
0      ,
3169   ,
5005   ,
1366   ,
1187   ,
2960   ,
4402   ,
7829   ,
4494   ,
4550   ,
4155   ,
0      ,
1670   ,
31707  ,
0      ,
2778   ,
6497   ,
2950   ,
7022   ,
3037   ,
5025   ,
3920   ,
1107   ,
5544   ,
4234   ,
1330   ,
6182   ,
0      ,
6093   ,
7193   ,
1472   ,
7313   ,
12034  ,
0      ,
11527  ,
11667  ,
0      ,
8122   ,
4849   ,
11876  ,
6439   ,
13482  ,
4171   ,
0      ,
2510   ,
5344   ,
6308   ,
5470   ,
3694   ,
3904   ,
3060   ,
1957   ,
3652   ,
2225   ,
1192   ,
3659   ,
3671   ,
2842   ,
0      ,
5014   ,
1665   ,
2556   ,
1066   ,
2900   ,
1324   ,
2125   ,
3245   ,
2785   ,
3922   ,
3338   ,
2431   ,
2794   ,
0      ,
6335   ,
1225   ,
2642   ,
6364   ,
4160   ,
3309   ,
0      ,
6834   ,
12081  ,
3435   ,
0      ,
7505   ,
8207   ,
3934   ,
8305   ,
10764  ,
11568  ,
3353   ,
0      ,
7731   ,
7976   ,
3563   ,
1029   ,
5288   ,
1333   ,
6704   ,
6018   ,
1413   ,
0      ,
1780   ,
11061  ,
12941  ,
5784   ,
6913   ,
8216   ,
0      ,
12014  ,
5836   ,
11487  ,
8744   ,
10846  ,
2219   ,
5146   ,
0      ,
5868   ,
3033   ,
6833   ,
5479   ,
5133   ,
4490   ,
6107   ,
5144   ,
4442   ,
5649   ,
2533   ,
5321   ,
1877   ,
0      
};

int main()
{
    uint64_t max[3] = {0, 0, 0};
    uint64_t current = 0;

    for (auto i : input)
    {
        current += i;
        if (i == 0)
        {
            if (current > max[2])
            {
                max[0] = max[1];
                max[1] = max[2];
                max[2] = current;
            }
            else if (current > max[1])
            {
                max[0] = max[1];
                max[1] = current;
            }
            else if (current > max[0])
            {
                max[0] = current;
            }
            current = 0;
        }
    }

    std::cout << "Part 1: " << max[2] << std::endl << "Part 2: " << max[0] + max[1] + max[2];

    return 0;
}