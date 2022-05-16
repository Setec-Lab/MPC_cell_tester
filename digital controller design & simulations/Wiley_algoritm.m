% @file Wiley_algoritm.m
% Digital Control of High-Frenquency Switched-Mode Power Converters
% 

clc
clear all 
s = tf('s');

%variables
rC=0.8*10^-3;
rL=30*10^-3;
L=1*10^-6;
C=200*10^-6;

Vg=5;
Io=5;
D=0.36;
Dprime=1-D;
tcntrl=400*10^-9;
Ts=1*10^-6;

Tdpwm=D*Ts;
td=tcntrl+Tdpwm;
Nr=1;
fs=1/Ts;

%plant arrays
A1 = [ -(rC+rL)/L -1/L; 1/C 0 ];
A0 = A1;
b1 = [ 1/L rC/L; 0 -1/C ];
b0 = [ 0 rC/L; 0 -1/C];
c1 = [1 0; rC 1];
c0 = c1;


A1i = A1^-1;
A0i = A0^-1;
Xdown = ((eye(2)-expm(A1*D*Ts)*expm(A0*Dprime*Ts))^-1)*(-expm(A1*D*Ts)*A0i*(eye(2)-expm(A0*Dprime*Ts))*b0-A1i*(eye(2)-expm(A1*D*Ts))*b1)*[Vg;Io];

Phi = expm(A0*(Ts-td))*expm(A1*D*Ts)*expm(A0*(td-D*Ts));
gamma = expm(A0*(Ts-td))*((A1-A0)*Xdown + (b1-b0)*[Vg;Io])*Ts;
delta = c0;

sys = ss(Phi,gamma,delta(1,:),0,Ts);
Giuz = tf(sys);
sys2 = ss(Phi,gamma,delta(2,:),0,Ts);
Gvuz = tf(sys2);

%bode(sys)

%Gvd=(9*(1+7.5*10^-6*s))/(30*10^-6*s^2+2.1*10^-5*s+1);

%Gvds = Vg*(1+s*rC*C)/(1+s*(rL+rC)*C+s^2*L*C);
%Xdown = ((eye(2)-exL+rC)*C+s^2*L*C);
%Gvds.outputdelay = td;
%Gvuz = (1/Nr)*c2d(Gvds,Ts,'imp');


% Target crossover frequency and phase margin
wc = 2*pi*100e3;
mphi = (pi/180)*45; % In radians

% Magnitude and phase of Tuz at the target crossover frequency
%[m,p] = bode(Tuz,wc);
[m,p0] = bode(sys2,wc);
%m=63*10^-3;
%p=-199;
p = (pi/180)*p0;
% Prewarping on wc
wcp = (2/Ts)*tan(wc*Ts/2);
% PD Design
wp = 2*pi*fs/pi;
pw = atan(wcp/wp);
wPD = 1/(tan(-pi+mphi-p+pw)/wcp);
GPD0 = sqrt(1+(wcp/wp)^2)/(m*(sqrt(1+(wcp/wPD)^2)));
% PI zero and high-frequency gain
wPI = wc/20;
GPIinf = 1;
% Proportional, Integral and Derivative Gains
Kp = GPIinf*GPD0*(1+wPI/wPD-2*wPI/wp);
Ki = 2*GPIinf*GPD0*wPI/wp;
Kd = GPIinf*GPD0/2*(1-wPI/wp)*(wp/wPD-1);
% PID Transfer function
z = tf('z',Ts);
Gcz = Kp + Ki/(1-z^-1) + Kd*(1-z^-1);

display(Gvuz)
display(Gcz)
display(Kp)
display(Ki)
display(Kd)
bode(Gvuz)