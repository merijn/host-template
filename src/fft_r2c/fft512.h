#define R float
#define E R
#define stride int
#define INT int
#define K(x) ((E) x)
#define DK(name,value) const E name = K(value)
#define WS(s,i) s*i
#define MAKE_VOLATILE_STRIDE(x,y) 0
#define FMA(a,b,c) a * b + c
#define FMS(a,b,c) a * b - c
#define FNMA(a,b,c) -a * b - c
#define FNMS(a,b,c) -a * b + c

__constant float w_2_256[512] = {
  1.0, 0.0, 0.9999247018391445, 1.2271538285719925e-2, 0.9996988186962042,
    2.4541228522912288e-2, 0.9993223845883495, 3.680722294135883e-2,
    0.9987954562051724, 4.9067674327418015e-2, 0.9981181129001492,
    6.132073630220858e-2, 0.9972904566786902, 7.356456359966743e-2,
    0.996312612182778, 8.57973123444399e-2, 0.9951847266721969,
    9.80171403295606e-2, 0.9939069700023561, 0.11022220729388306,
    0.99247953459871, 0.1224106751992162, 0.99090263542778,
    0.13458070850712617, 0.989176509964781, 0.14673047445536175,
    0.9873014181578584, 0.15885814333386145, 0.9852776423889412,
    0.17096188876030122, 0.9831054874312163, 0.18303988795514095,
    0.9807852804032304, 0.19509032201612825, 0.9783173707196277,
    0.20711137619221856, 0.9757021300385286, 0.2191012401568698,
    0.9729399522055602, 0.2310581082806711, 0.970031253194544,
    0.24298017990326387, 0.9669764710448521, 0.25486565960451457,
    0.9637760657954398, 0.26671275747489837, 0.9604305194155658,
    0.27851968938505306, 0.9569403357322088, 0.29028467725446233,
    0.9533060403541939, 0.3020059493192281, 0.9495281805930367,
    0.3136817403988915, 0.9456073253805213, 0.3253102921622629,
    0.9415440651830208, 0.33688985339222005, 0.937339011912575,
    0.34841868024943456, 0.932992798834739, 0.3598950365349881,
    0.9285060804732156, 0.37131719395183754, 0.9238795325112867,
    0.3826834323650898, 0.9191138516900578, 0.3939920400610481,
    0.9142097557035307, 0.40524131400498986, 0.9091679830905224,
    0.41642956009763715, 0.9039892931234433, 0.4275550934302821,
    0.8986744656939538, 0.43861623853852766, 0.8932243011955153,
    0.44961132965460654, 0.8876396204028539, 0.46053871095824,
    0.881921264348355, 0.47139673682599764, 0.8760700941954066,
    0.4821837720791227, 0.8700869911087115, 0.49289819222978404,
    0.8639728561215868, 0.5035383837257176, 0.8577286100002721,
    0.5141027441932217, 0.8513551931052652, 0.524589682678469,
    0.8448535652497071, 0.5349976198870972, 0.8382247055548381,
    0.5453249884220465, 0.8314696123025452, 0.5555702330196022,
    0.8245893027850253, 0.5657318107836131, 0.8175848131515837,
    0.5758081914178453, 0.8104571982525948, 0.5857978574564389,
    0.8032075314806449, 0.5956993044924334, 0.7958369046088836,
    0.6055110414043255, 0.7883464276266063, 0.6152315905806268,
    0.7807372285720945, 0.6248594881423863, 0.773010453362737,
    0.6343932841636455, 0.765167265622459, 0.6438315428897914,
    0.7572088465064846, 0.6531728429537768, 0.7491363945234594,
    0.6624157775901718, 0.7409511253549591, 0.6715589548470183,
    0.7326542716724128, 0.680600997795453, 0.724247082951467,
    0.6895405447370668, 0.7157308252838186, 0.6983762494089729,
    0.7071067811865476, 0.7071067811865475, 0.6983762494089729,
    0.7157308252838186, 0.6895405447370669, 0.7242470829514669,
    0.6806009977954531, 0.7326542716724128, 0.6715589548470183,
    0.7409511253549591, 0.6624157775901718, 0.7491363945234593,
    0.6531728429537768, 0.7572088465064845, 0.6438315428897915,
    0.765167265622459, 0.6343932841636455, 0.773010453362737,
    0.6248594881423865, 0.7807372285720944, 0.6152315905806268,
    0.7883464276266062, 0.6055110414043255, 0.7958369046088835,
    0.5956993044924335, 0.8032075314806448, 0.5857978574564389,
    0.8104571982525948, 0.5758081914178453, 0.8175848131515837,
    0.5657318107836132, 0.8245893027850253, 0.5555702330196023,
    0.8314696123025452, 0.5453249884220465, 0.838224705554838,
    0.5349976198870973, 0.844853565249707, 0.5245896826784688,
    0.8513551931052652, 0.5141027441932217, 0.8577286100002721,
    0.5035383837257176, 0.8639728561215867, 0.4928981922297841,
    0.8700869911087113, 0.48218377207912283, 0.8760700941954066,
    0.4713967368259978, 0.8819212643483549, 0.46053871095824,
    0.8876396204028539, 0.4496113296546066, 0.8932243011955153,
    0.4386162385385277, 0.8986744656939538, 0.4275550934302822,
    0.9039892931234433, 0.4164295600976373, 0.9091679830905223,
    0.40524131400498986, 0.9142097557035307, 0.3939920400610481,
    0.9191138516900578, 0.38268343236508984, 0.9238795325112867,
    0.3713171939518376, 0.9285060804732155, 0.3598950365349883,
    0.9329927988347388, 0.3484186802494345, 0.937339011912575,
    0.33688985339222005, 0.9415440651830208, 0.325310292162263,
    0.9456073253805213, 0.3136817403988916, 0.9495281805930367,
    0.3020059493192282, 0.9533060403541938, 0.29028467725446233,
    0.9569403357322089, 0.27851968938505306, 0.9604305194155658,
    0.2667127574748984, 0.9637760657954398, 0.2548656596045146,
    0.9669764710448521, 0.24298017990326398, 0.970031253194544,
    0.23105810828067128, 0.9729399522055601, 0.21910124015686977,
    0.9757021300385286, 0.20711137619221856, 0.9783173707196277,
    0.19509032201612833, 0.9807852804032304, 0.18303988795514106,
    0.9831054874312163, 0.17096188876030136, 0.9852776423889412,
    0.1588581433338614, 0.9873014181578584, 0.14673047445536175,
    0.989176509964781, 0.13458070850712622, 0.99090263542778,
    0.12241067519921628, 0.99247953459871, 0.11022220729388318,
    0.9939069700023561, 9.801714032956077e-2, 0.9951847266721968,
    8.579731234443988e-2, 0.996312612182778, 7.356456359966745e-2,
    0.9972904566786902, 6.132073630220865e-2, 0.9981181129001492,
    4.9067674327418126e-2, 0.9987954562051724, 3.680722294135899e-2,
    0.9993223845883495, 2.4541228522912264e-2, 0.9996988186962042,
    1.2271538285719944e-2, 0.9999247018391445, 6.123233995736766e-17, 1.0,
    -1.2271538285719823e-2, 0.9999247018391445, -2.4541228522912142e-2,
    0.9996988186962042, -3.6807222941358866e-2, 0.9993223845883495,
    -4.906767432741801e-2, 0.9987954562051724, -6.132073630220853e-2,
    0.9981181129001492, -7.356456359966733e-2, 0.9972904566786902,
    -8.579731234443976e-2, 0.996312612182778, -9.801714032956065e-2,
    0.9951847266721969, -0.11022220729388306, 0.9939069700023561,
    -0.12241067519921615, 0.99247953459871, -0.1345807085071261,
    0.99090263542778, -0.14673047445536164, 0.989176509964781,
    -0.15885814333386128, 0.9873014181578584, -0.17096188876030124,
    0.9852776423889412, -0.18303988795514092, 0.9831054874312163,
    -0.1950903220161282, 0.9807852804032304, -0.20711137619221845,
    0.9783173707196277, -0.21910124015686966, 0.9757021300385286,
    -0.23105810828067114, 0.9729399522055602, -0.24298017990326387,
    0.970031253194544, -0.2548656596045145, 0.9669764710448521,
    -0.2667127574748983, 0.9637760657954398, -0.27851968938505295,
    0.9604305194155659, -0.29028467725446216, 0.9569403357322089,
    -0.3020059493192281, 0.9533060403541939, -0.3136817403988914,
    0.9495281805930367, -0.32531029216226287, 0.9456073253805214,
    -0.33688985339221994, 0.9415440651830208, -0.3484186802494344,
    0.937339011912575, -0.35989503653498817, 0.9329927988347388,
    -0.3713171939518375, 0.9285060804732156, -0.3826834323650897,
    0.9238795325112867, -0.393992040061048, 0.9191138516900578,
    -0.40524131400498975, 0.9142097557035307, -0.416429560097637,
    0.9091679830905225, -0.42755509343028186, 0.9039892931234434,
    -0.4386162385385274, 0.8986744656939539, -0.4496113296546067,
    0.8932243011955152, -0.46053871095824006, 0.8876396204028539,
    -0.4713967368259977, 0.881921264348355, -0.4821837720791227,
    0.8760700941954066, -0.492898192229784, 0.8700869911087115,
    -0.5035383837257175, 0.8639728561215868, -0.5141027441932217,
    0.8577286100002721, -0.5245896826784687, 0.8513551931052652,
    -0.534997619887097, 0.8448535652497072, -0.5453249884220462,
    0.8382247055548382, -0.555570233019602, 0.8314696123025455,
    -0.5657318107836132, 0.8245893027850252, -0.5758081914178453,
    0.8175848131515837, -0.5857978574564389, 0.8104571982525948,
    -0.5956993044924334, 0.8032075314806449, -0.6055110414043254,
    0.7958369046088836, -0.6152315905806267, 0.7883464276266063,
    -0.6248594881423862, 0.7807372285720946, -0.6343932841636454,
    0.7730104533627371, -0.6438315428897913, 0.7651672656224591,
    -0.6531728429537765, 0.7572088465064847, -0.6624157775901719,
    0.7491363945234593, -0.6715589548470184, 0.740951125354959,
    -0.680600997795453, 0.7326542716724128, -0.6895405447370669,
    0.7242470829514669, -0.6983762494089728, 0.7157308252838187,
    -0.7071067811865475, 0.7071067811865476, -0.7157308252838186,
    0.6983762494089729, -0.7242470829514668, 0.689540544737067,
    -0.7326542716724127, 0.6806009977954532, -0.7409511253549589,
    0.6715589548470186, -0.7491363945234591, 0.662415777590172,
    -0.7572088465064846, 0.6531728429537766, -0.765167265622459,
    0.6438315428897914, -0.773010453362737, 0.6343932841636455,
    -0.7807372285720945, 0.6248594881423863, -0.7883464276266062,
    0.6152315905806269, -0.7958369046088835, 0.6055110414043257,
    -0.8032075314806448, 0.5956993044924335, -0.8104571982525947,
    0.585797857456439, -0.8175848131515836, 0.5758081914178454,
    -0.8245893027850251, 0.5657318107836135, -0.8314696123025453,
    0.5555702330196022, -0.8382247055548381, 0.5453249884220464,
    -0.8448535652497071, 0.5349976198870972, -0.8513551931052652,
    0.524589682678469, -0.857728610000272, 0.5141027441932218,
    -0.8639728561215867, 0.5035383837257177, -0.8700869911087113,
    0.49289819222978415, -0.8760700941954065, 0.4821837720791229,
    -0.8819212643483549, 0.47139673682599786, -0.8876396204028538,
    0.4605387109582402, -0.8932243011955152, 0.4496113296546069,
    -0.8986744656939539, 0.43861623853852755, -0.9039892931234433,
    0.42755509343028203, -0.9091679830905224, 0.41642956009763715,
    -0.9142097557035307, 0.4052413140049899, -0.9191138516900578,
    0.39399204006104815, -0.9238795325112867, 0.3826834323650899,
    -0.9285060804732155, 0.3713171939518377, -0.9329927988347388,
    0.35989503653498833, -0.9373390119125748, 0.3484186802494348,
    -0.9415440651830207, 0.33688985339222033, -0.9456073253805212,
    0.32531029216226326, -0.9495281805930367, 0.3136817403988914,
    -0.9533060403541939, 0.30200594931922803, -0.9569403357322088,
    0.2902846772544624, -0.9604305194155658, 0.27851968938505317,
    -0.9637760657954398, 0.2667127574748985, -0.9669764710448521,
    0.2548656596045147, -0.970031253194544, 0.24298017990326407,
    -0.9729399522055601, 0.23105810828067133, -0.9757021300385285,
    0.21910124015687005, -0.9783173707196275, 0.20711137619221884,
    -0.9807852804032304, 0.1950903220161286, -0.9831054874312163,
    0.1830398879551409, -0.9852776423889412, 0.17096188876030122,
    -0.9873014181578584, 0.15885814333386147, -0.989176509964781,
    0.1467304744553618, -0.99090263542778, 0.13458070850712628,
    -0.99247953459871, 0.12241067519921635, -0.9939069700023561,
    0.11022220729388324, -0.9951847266721968, 9.801714032956083e-2,
    -0.996312612182778, 8.579731234444016e-2, -0.9972904566786902,
    7.356456359966773e-2, -0.9981181129001492, 6.132073630220849e-2,
    -0.9987954562051724, 4.9067674327417966e-2, -0.9993223845883495,
    3.680722294135883e-2, -0.9996988186962042, 2.4541228522912326e-2,
    -0.9999247018391445, 1.2271538285720007e-2
};

__constant float w_4_4[24] = {
  1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.9238795325112867, 0.3826834323650898,
    0.7071067811865476, 0.7071067811865475, 0.38268343236508984,
    0.9238795325112867, 0.7071067811865476, 0.7071067811865475,
    6.123233995736766e-17, 1.0, -0.7071067811865475, 0.7071067811865476,
    0.38268343236508984, 0.9238795325112867, -0.7071067811865475,
    0.7071067811865476, -0.9238795325112868, -0.38268343236508967
};

__constant float w_4_16[96] = {
  1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.9951847266721969, 9.80171403295606e-2,
    0.9807852804032304, 0.19509032201612825, 0.9569403357322088,
    0.29028467725446233, 0.9807852804032304, 0.19509032201612825,
    0.9238795325112867, 0.3826834323650898, 0.8314696123025452,
    0.5555702330196022, 0.9569403357322088, 0.29028467725446233,
    0.8314696123025452, 0.5555702330196022, 0.6343932841636455,
    0.773010453362737, 0.9238795325112867, 0.3826834323650898,
    0.7071067811865476, 0.7071067811865475, 0.38268343236508984,
    0.9238795325112867, 0.881921264348355, 0.47139673682599764,
    0.5555702330196023, 0.8314696123025452, 9.801714032956077e-2,
    0.9951847266721968, 0.8314696123025452, 0.5555702330196022,
    0.38268343236508984, 0.9238795325112867, -0.1950903220161282,
    0.9807852804032304, 0.773010453362737, 0.6343932841636455,
    0.19509032201612833, 0.9807852804032304, -0.4713967368259977,
    0.881921264348355, 0.7071067811865476, 0.7071067811865475,
    6.123233995736766e-17, 1.0, -0.7071067811865475, 0.7071067811865476,
    0.6343932841636455, 0.773010453362737, -0.1950903220161282,
    0.9807852804032304, -0.8819212643483549, 0.47139673682599786,
    0.5555702330196023, 0.8314696123025452, -0.3826834323650897,
    0.9238795325112867, -0.9807852804032304, 0.1950903220161286,
    0.4713967368259978, 0.8819212643483549, -0.555570233019602,
    0.8314696123025455, -0.9951847266721969, -9.801714032956059e-2,
    0.38268343236508984, 0.9238795325112867, -0.7071067811865475,
    0.7071067811865476, -0.9238795325112868, -0.38268343236508967,
    0.29028467725446233, 0.9569403357322089, -0.8314696123025453,
    0.5555702330196022, -0.7730104533627371, -0.6343932841636453,
    0.19509032201612833, 0.9807852804032304, -0.9238795325112867,
    0.3826834323650899, -0.5555702330196022, -0.8314696123025452,
    9.801714032956077e-2, 0.9951847266721968, -0.9807852804032304,
    0.1950903220161286, -0.29028467725446244, -0.9569403357322088
};

__constant float w_4_64[384] = {
  1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.9996988186962042, 2.4541228522912288e-2,
    0.9987954562051724, 4.9067674327418015e-2, 0.9972904566786902,
    7.356456359966743e-2, 0.9987954562051724, 4.9067674327418015e-2,
    0.9951847266721969, 9.80171403295606e-2, 0.989176509964781,
    0.14673047445536175, 0.9972904566786902, 7.356456359966743e-2,
    0.989176509964781, 0.14673047445536175, 0.9757021300385286,
    0.2191012401568698, 0.9951847266721969, 9.80171403295606e-2,
    0.9807852804032304, 0.19509032201612825, 0.9569403357322088,
    0.29028467725446233, 0.99247953459871, 0.1224106751992162,
    0.970031253194544, 0.24298017990326387, 0.932992798834739,
    0.3598950365349881, 0.989176509964781, 0.14673047445536175,
    0.9569403357322088, 0.29028467725446233, 0.9039892931234433,
    0.4275550934302821, 0.9852776423889412, 0.17096188876030122,
    0.9415440651830208, 0.33688985339222005, 0.8700869911087115,
    0.49289819222978404, 0.9807852804032304, 0.19509032201612825,
    0.9238795325112867, 0.3826834323650898, 0.8314696123025452,
    0.5555702330196022, 0.9757021300385286, 0.2191012401568698,
    0.9039892931234433, 0.4275550934302821, 0.7883464276266063,
    0.6152315905806268, 0.970031253194544, 0.24298017990326387,
    0.881921264348355, 0.47139673682599764, 0.7409511253549591,
    0.6715589548470183, 0.9637760657954398, 0.26671275747489837,
    0.8577286100002721, 0.5141027441932217, 0.6895405447370669,
    0.7242470829514669, 0.9569403357322088, 0.29028467725446233,
    0.8314696123025452, 0.5555702330196022, 0.6343932841636455,
    0.773010453362737, 0.9495281805930367, 0.3136817403988915,
    0.8032075314806449, 0.5956993044924334, 0.5758081914178453,
    0.8175848131515837, 0.9415440651830208, 0.33688985339222005,
    0.773010453362737, 0.6343932841636455, 0.5141027441932217,
    0.8577286100002721, 0.932992798834739, 0.3598950365349881,
    0.7409511253549591, 0.6715589548470183, 0.4496113296546066,
    0.8932243011955153, 0.9238795325112867, 0.3826834323650898,
    0.7071067811865476, 0.7071067811865475, 0.38268343236508984,
    0.9238795325112867, 0.9142097557035307, 0.40524131400498986,
    0.6715589548470183, 0.7409511253549591, 0.3136817403988916,
    0.9495281805930367, 0.9039892931234433, 0.4275550934302821,
    0.6343932841636455, 0.773010453362737, 0.24298017990326398,
    0.970031253194544, 0.8932243011955153, 0.44961132965460654,
    0.5956993044924335, 0.8032075314806448, 0.17096188876030136,
    0.9852776423889412, 0.881921264348355, 0.47139673682599764,
    0.5555702330196023, 0.8314696123025452, 9.801714032956077e-2,
    0.9951847266721968, 0.8700869911087115, 0.49289819222978404,
    0.5141027441932217, 0.8577286100002721, 2.4541228522912264e-2,
    0.9996988186962042, 0.8577286100002721, 0.5141027441932217,
    0.4713967368259978, 0.8819212643483549, -4.906767432741801e-2,
    0.9987954562051724, 0.8448535652497071, 0.5349976198870972,
    0.4275550934302822, 0.9039892931234433, -0.12241067519921615,
    0.99247953459871, 0.8314696123025452, 0.5555702330196022,
    0.38268343236508984, 0.9238795325112867, -0.1950903220161282,
    0.9807852804032304, 0.8175848131515837, 0.5758081914178453,
    0.33688985339222005, 0.9415440651830208, -0.2667127574748983,
    0.9637760657954398, 0.8032075314806449, 0.5956993044924334,
    0.29028467725446233, 0.9569403357322089, -0.33688985339221994,
    0.9415440651830208, 0.7883464276266063, 0.6152315905806268,
    0.24298017990326398, 0.970031253194544, -0.40524131400498975,
    0.9142097557035307, 0.773010453362737, 0.6343932841636455,
    0.19509032201612833, 0.9807852804032304, -0.4713967368259977,
    0.881921264348355, 0.7572088465064846, 0.6531728429537768,
    0.14673047445536175, 0.989176509964781, -0.534997619887097,
    0.8448535652497072, 0.7409511253549591, 0.6715589548470183,
    9.801714032956077e-2, 0.9951847266721968, -0.5956993044924334,
    0.8032075314806449, 0.724247082951467, 0.6895405447370668,
    4.9067674327418126e-2, 0.9987954562051724, -0.6531728429537765,
    0.7572088465064847, 0.7071067811865476, 0.7071067811865475,
    6.123233995736766e-17, 1.0, -0.7071067811865475, 0.7071067811865476,
    0.6895405447370669, 0.7242470829514669, -4.906767432741801e-2,
    0.9987954562051724, -0.7572088465064846, 0.6531728429537766,
    0.6715589548470183, 0.7409511253549591, -9.801714032956065e-2,
    0.9951847266721969, -0.8032075314806448, 0.5956993044924335,
    0.6531728429537768, 0.7572088465064845, -0.14673047445536164,
    0.989176509964781, -0.8448535652497071, 0.5349976198870972,
    0.6343932841636455, 0.773010453362737, -0.1950903220161282,
    0.9807852804032304, -0.8819212643483549, 0.47139673682599786,
    0.6152315905806268, 0.7883464276266062, -0.24298017990326387,
    0.970031253194544, -0.9142097557035307, 0.4052413140049899,
    0.5956993044924335, 0.8032075314806448, -0.29028467725446216,
    0.9569403357322089, -0.9415440651830207, 0.33688985339222033,
    0.5758081914178453, 0.8175848131515837, -0.33688985339221994,
    0.9415440651830208, -0.9637760657954398, 0.2667127574748985,
    0.5555702330196023, 0.8314696123025452, -0.3826834323650897,
    0.9238795325112867, -0.9807852804032304, 0.1950903220161286,
    0.5349976198870973, 0.844853565249707, -0.42755509343028186,
    0.9039892931234434, -0.99247953459871, 0.12241067519921635,
    0.5141027441932217, 0.8577286100002721, -0.4713967368259977,
    0.881921264348355, -0.9987954562051724, 4.9067674327417966e-2,
    0.4928981922297841, 0.8700869911087113, -0.5141027441932217,
    0.8577286100002721, -0.9996988186962042, -2.454122852291208e-2,
    0.4713967368259978, 0.8819212643483549, -0.555570233019602,
    0.8314696123025455, -0.9951847266721969, -9.801714032956059e-2,
    0.4496113296546066, 0.8932243011955153, -0.5956993044924334,
    0.8032075314806449, -0.9852776423889413, -0.17096188876030097,
    0.4275550934302822, 0.9039892931234433, -0.6343932841636454,
    0.7730104533627371, -0.970031253194544, -0.24298017990326382,
    0.40524131400498986, 0.9142097557035307, -0.6715589548470184,
    0.740951125354959, -0.9495281805930368, -0.3136817403988912,
    0.38268343236508984, 0.9238795325112867, -0.7071067811865475,
    0.7071067811865476, -0.9238795325112868, -0.38268343236508967,
    0.3598950365349883, 0.9329927988347388, -0.7409511253549589,
    0.6715589548470186, -0.8932243011955153, -0.44961132965460665,
    0.33688985339222005, 0.9415440651830208, -0.773010453362737,
    0.6343932841636455, -0.8577286100002721, -0.5141027441932216,
    0.3136817403988916, 0.9495281805930367, -0.8032075314806448,
    0.5956993044924335, -0.8175848131515837, -0.5758081914178453,
    0.29028467725446233, 0.9569403357322089, -0.8314696123025453,
    0.5555702330196022, -0.7730104533627371, -0.6343932841636453,
    0.2667127574748984, 0.9637760657954398, -0.857728610000272,
    0.5141027441932218, -0.724247082951467, -0.6895405447370668,
    0.24298017990326398, 0.970031253194544, -0.8819212643483549,
    0.47139673682599786, -0.6715589548470187, -0.7409511253549589,
    0.21910124015686977, 0.9757021300385286, -0.9039892931234433,
    0.42755509343028203, -0.6152315905806273, -0.7883464276266059,
    0.19509032201612833, 0.9807852804032304, -0.9238795325112867,
    0.3826834323650899, -0.5555702330196022, -0.8314696123025452,
    0.17096188876030136, 0.9852776423889412, -0.9415440651830207,
    0.33688985339222033, -0.4928981922297842, -0.8700869911087113,
    0.14673047445536175, 0.989176509964781, -0.9569403357322088,
    0.2902846772544624, -0.4275550934302825, -0.9039892931234431,
    0.12241067519921628, 0.99247953459871, -0.970031253194544,
    0.24298017990326407, -0.35989503653498794, -0.932992798834739,
    9.801714032956077e-2, 0.9951847266721968, -0.9807852804032304,
    0.1950903220161286, -0.29028467725446244, -0.9569403357322088,
    7.356456359966745e-2, 0.9972904566786902, -0.989176509964781,
    0.1467304744553618, -0.2191012401568701, -0.9757021300385285,
    4.9067674327418126e-2, 0.9987954562051724, -0.9951847266721968,
    9.801714032956083e-2, -0.1467304744553623, -0.9891765099647809,
    2.4541228522912264e-2, 0.9996988186962042, -0.9987954562051724,
    4.9067674327417966e-2, -7.356456359966736e-2, -0.9972904566786902
};

/* Generated by: ./genfft/gen_twiddle.native -n 2 -name twiddle_2 -compact -standalone -opencl */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 4 additions, 2 multiplications, 2 fused multiply/add),
 * 9 stack variables, 0 constants, and 8 memory accesses
 */
void
twiddle_2 (R * ri, R * ii, __constant const R * W, stride rs, INT mb, INT me,
           INT ms)
{
  {
    INT m;
    for (m = mb, W = W + (mb * 2); m < me;
         m = m + 1, ri = ri + ms, ii = ii + ms, W =
         W + 2, MAKE_VOLATILE_STRIDE (4, rs))
      {
        E T1, T8, T6, T7;
        T1 = ri[0];
        T8 = ii[0];
        {
          E T3, T5, T2, T4;
          T3 = ri[WS (rs, 1)];
          T5 = ii[WS (rs, 1)];
          T2 = W[0];
          T4 = W[1];
          T6 = FMA (T2, T3, T4 * T5);
          T7 = FNMS (T4, T3, T2 * T5);
        }
        ri[WS (rs, 1)] = T1 - T6;
        ii[WS (rs, 1)] = T8 - T7;
        ri[0] = T1 + T6;
        ii[0] = T7 + T8;
      }
  }
}

/* Generated by: ./genfft/gen_twiddle.native -n 4 -name twiddle_4 -compact -standalone -opencl */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 13 stack variables, 0 constants, and 16 memory accesses
 */
void
twiddle_4 (R * ri, R * ii, __constant const R * W, stride rs, INT mb, INT me,
           INT ms)
{
  {
    INT m;
    for (m = mb, W = W + (mb * 6); m < me;
         m = m + 1, ri = ri + ms, ii = ii + ms, W =
         W + 6, MAKE_VOLATILE_STRIDE (8, rs))
      {
        E T1, Tp, T6, To, Tc, Tk, Th, Tl;
        T1 = ri[0];
        Tp = ii[0];
        {
          E T3, T5, T2, T4;
          T3 = ri[WS (rs, 2)];
          T5 = ii[WS (rs, 2)];
          T2 = W[2];
          T4 = W[3];
          T6 = FMA (T2, T3, T4 * T5);
          To = FNMS (T4, T3, T2 * T5);
        }
        {
          E T9, Tb, T8, Ta;
          T9 = ri[WS (rs, 1)];
          Tb = ii[WS (rs, 1)];
          T8 = W[0];
          Ta = W[1];
          Tc = FMA (T8, T9, Ta * Tb);
          Tk = FNMS (Ta, T9, T8 * Tb);
        }
        {
          E Te, Tg, Td, Tf;
          Te = ri[WS (rs, 3)];
          Tg = ii[WS (rs, 3)];
          Td = W[4];
          Tf = W[5];
          Th = FMA (Td, Te, Tf * Tg);
          Tl = FNMS (Tf, Te, Td * Tg);
        }
        {
          E T7, Ti, Tn, Tq;
          T7 = T1 + T6;
          Ti = Tc + Th;
          ri[WS (rs, 2)] = T7 - Ti;
          ri[0] = T7 + Ti;
          Tn = Tk + Tl;
          Tq = To + Tp;
          ii[0] = Tn + Tq;
          ii[WS (rs, 2)] = Tq - Tn;
        }
        {
          E Tj, Tm, Tr, Ts;
          Tj = T1 - T6;
          Tm = Tk - Tl;
          ri[WS (rs, 3)] = Tj - Tm;
          ri[WS (rs, 1)] = Tj + Tm;
          Tr = Tp - To;
          Ts = Tc - Th;
          ii[WS (rs, 1)] = Tr - Ts;
          ii[WS (rs, 3)] = Ts + Tr;
        }
      }
  }
}

/* Generated by: ./genfft/gen_notw.native -n 4 -name notw_4 -compact -standalone -opencl */

/*
 * This function contains 16 FP additions, 0 FP multiplications,
 * (or, 16 additions, 0 multiplications, 0 fused multiply/add),
 * 13 stack variables, 0 constants, and 16 memory accesses
 */
void
notw_4 (const R * ri, const R * ii, R * ro, R * io, stride is, stride os,
        INT v, INT ivs, INT ovs)
{
  {
    INT i;
    for (i = v; i > 0;
         i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io =
         io + ovs, MAKE_VOLATILE_STRIDE (16, is), MAKE_VOLATILE_STRIDE (16,
                                                                        os))
      {
        E T3, Tb, T9, Tf, T6, Ta, Te, Tg;
        {
          E T1, T2, T7, T8;
          T1 = ri[0];
          T2 = ri[WS (is, 2)];
          T3 = T1 + T2;
          Tb = T1 - T2;
          T7 = ii[0];
          T8 = ii[WS (is, 2)];
          T9 = T7 - T8;
          Tf = T7 + T8;
        }
        {
          E T4, T5, Tc, Td;
          T4 = ri[WS (is, 1)];
          T5 = ri[WS (is, 3)];
          T6 = T4 + T5;
          Ta = T4 - T5;
          Tc = ii[WS (is, 1)];
          Td = ii[WS (is, 3)];
          Te = Tc - Td;
          Tg = Tc + Td;
        }
        ro[WS (os, 2)] = T3 - T6;
        io[WS (os, 2)] = Tf - Tg;
        ro[0] = T3 + T6;
        io[0] = Tf + Tg;
        io[WS (os, 1)] = T9 - Ta;
        ro[WS (os, 1)] = Tb + Te;
        io[WS (os, 3)] = Ta + T9;
        ro[WS (os, 3)] = Tb - Te;
      }
  }
}

void fft(float const *input, float *output) {
    notw_4(input, input + 1, output, output + 1, 256, 2, 4, 64, 8);
    twiddle_4(output, output + 1, w_4_4, 8, 0, 4, 2);
    notw_4(input + 16, input + 17, output + 32, output + 33, 256, 2, 4, 64, 8);
    twiddle_4(output + 32, output + 33, w_4_4, 8, 0, 4, 2);
    notw_4(input + 32, input + 33, output + 64, output + 65, 256, 2, 4, 64, 8);
    twiddle_4(output + 64, output + 65, w_4_4, 8, 0, 4, 2);
    notw_4(input + 48, input + 49, output + 96, output + 97, 256, 2, 4, 64, 8);
    twiddle_4(output + 96, output + 97, w_4_4, 8, 0, 4, 2);
    twiddle_4(output, output + 1, w_4_16, 32, 0, 16, 2);
    notw_4(input + 4, input + 5, output + 128, output + 129, 256, 2, 4, 64, 8);
    twiddle_4(output + 128, output + 129, w_4_4, 8, 0, 4, 2);
    notw_4(input + 20, input + 21, output + 160, output + 161, 256, 2, 4, 64, 8);
    twiddle_4(output + 160, output + 161, w_4_4, 8, 0, 4, 2);
    notw_4(input + 36, input + 37, output + 192, output + 193, 256, 2, 4, 64, 8);
    twiddle_4(output + 192, output + 193, w_4_4, 8, 0, 4, 2);
    notw_4(input + 52, input + 53, output + 224, output + 225, 256, 2, 4, 64, 8);
    twiddle_4(output + 224, output + 225, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 128, output + 129, w_4_16, 32, 0, 16, 2);
    notw_4(input + 8, input + 9, output + 256, output + 257, 256, 2, 4, 64, 8);
    twiddle_4(output + 256, output + 257, w_4_4, 8, 0, 4, 2);
    notw_4(input + 24, input + 25, output + 288, output + 289, 256, 2, 4, 64, 8);
    twiddle_4(output + 288, output + 289, w_4_4, 8, 0, 4, 2);
    notw_4(input + 40, input + 41, output + 320, output + 321, 256, 2, 4, 64, 8);
    twiddle_4(output + 320, output + 321, w_4_4, 8, 0, 4, 2);
    notw_4(input + 56, input + 57, output + 352, output + 353, 256, 2, 4, 64, 8);
    twiddle_4(output + 352, output + 353, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 256, output + 257, w_4_16, 32, 0, 16, 2);
    notw_4(input + 12, input + 13, output + 384, output + 385, 256, 2, 4, 64, 8);
    twiddle_4(output + 384, output + 385, w_4_4, 8, 0, 4, 2);
    notw_4(input + 28, input + 29, output + 416, output + 417, 256, 2, 4, 64, 8);
    twiddle_4(output + 416, output + 417, w_4_4, 8, 0, 4, 2);
    notw_4(input + 44, input + 45, output + 448, output + 449, 256, 2, 4, 64, 8);
    twiddle_4(output + 448, output + 449, w_4_4, 8, 0, 4, 2);
    notw_4(input + 60, input + 61, output + 480, output + 481, 256, 2, 4, 64, 8);
    twiddle_4(output + 480, output + 481, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 384, output + 385, w_4_16, 32, 0, 16, 2);
    twiddle_4(output, output + 1, w_4_64, 128, 0, 64, 2);
    notw_4(input + 2, input + 3, output + 512, output + 513, 256, 2, 4, 64, 8);
    twiddle_4(output + 512, output + 513, w_4_4, 8, 0, 4, 2);
    notw_4(input + 18, input + 19, output + 544, output + 545, 256, 2, 4, 64, 8);
    twiddle_4(output + 544, output + 545, w_4_4, 8, 0, 4, 2);
    notw_4(input + 34, input + 35, output + 576, output + 577, 256, 2, 4, 64, 8);
    twiddle_4(output + 576, output + 577, w_4_4, 8, 0, 4, 2);
    notw_4(input + 50, input + 51, output + 608, output + 609, 256, 2, 4, 64, 8);
    twiddle_4(output + 608, output + 609, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 512, output + 513, w_4_16, 32, 0, 16, 2);
    notw_4(input + 6, input + 7, output + 640, output + 641, 256, 2, 4, 64, 8);
    twiddle_4(output + 640, output + 641, w_4_4, 8, 0, 4, 2);
    notw_4(input + 22, input + 23, output + 672, output + 673, 256, 2, 4, 64, 8);
    twiddle_4(output + 672, output + 673, w_4_4, 8, 0, 4, 2);
    notw_4(input + 38, input + 39, output + 704, output + 705, 256, 2, 4, 64, 8);
    twiddle_4(output + 704, output + 705, w_4_4, 8, 0, 4, 2);
    notw_4(input + 54, input + 55, output + 736, output + 737, 256, 2, 4, 64, 8);
    twiddle_4(output + 736, output + 737, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 640, output + 641, w_4_16, 32, 0, 16, 2);
    notw_4(input + 10, input + 11, output + 768, output + 769, 256, 2, 4, 64, 8);
    twiddle_4(output + 768, output + 769, w_4_4, 8, 0, 4, 2);
    notw_4(input + 26, input + 27, output + 800, output + 801, 256, 2, 4, 64, 8);
    twiddle_4(output + 800, output + 801, w_4_4, 8, 0, 4, 2);
    notw_4(input + 42, input + 43, output + 832, output + 833, 256, 2, 4, 64, 8);
    twiddle_4(output + 832, output + 833, w_4_4, 8, 0, 4, 2);
    notw_4(input + 58, input + 59, output + 864, output + 865, 256, 2, 4, 64, 8);
    twiddle_4(output + 864, output + 865, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 768, output + 769, w_4_16, 32, 0, 16, 2);
    notw_4(input + 14, input + 15, output + 896, output + 897, 256, 2, 4, 64, 8);
    twiddle_4(output + 896, output + 897, w_4_4, 8, 0, 4, 2);
    notw_4(input + 30, input + 31, output + 928, output + 929, 256, 2, 4, 64, 8);
    twiddle_4(output + 928, output + 929, w_4_4, 8, 0, 4, 2);
    notw_4(input + 46, input + 47, output + 960, output + 961, 256, 2, 4, 64, 8);
    twiddle_4(output + 960, output + 961, w_4_4, 8, 0, 4, 2);
    notw_4(input + 62, input + 63, output + 992, output + 993, 256, 2, 4, 64, 8);
    twiddle_4(output + 992, output + 993, w_4_4, 8, 0, 4, 2);
    twiddle_4(output + 896, output + 897, w_4_16, 32, 0, 16, 2);
    twiddle_4(output + 512, output + 513, w_4_64, 128, 0, 64, 2);
    twiddle_2(output, output + 1, w_2_256, 512, 0, 256, 2);
}

