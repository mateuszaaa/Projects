function system = generuj_model(Kp,T1,T2,T3)
%obliczanie modelu

T1=tf(1,[T1 1]);
T2=tf(1,[T2 1]);
T3=tf(1,[T3 1]);

system=Kp*T1*T2*T3*tf(1,[1 0]);