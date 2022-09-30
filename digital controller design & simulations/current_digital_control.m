% @file digital_control.m
% @author Kevin Gomez Villagra
% @date 17 Feb 2022
% @brief definitions for the design of the digital control of the BDC prototype.
% @par Institution:
% Costa Rica Institute of Technology.
% @par Mail:
% kevinxnor1419@estudiantec.cr

clc
clear all
s = tf('s');

%variables
rC=20*10^-3;
rL=560*10^-3;
L=470*10^-6;
C=470*10^-6;

Vg=3.8;
Io=1;
D=0.5;
Dprime=1-D;

%tcntrl=2*10^-6+2*10^-6; % Time taken to propagate the signal througt the ADC with 12 bits of resolution and FOSC/32 plus execution time by the CPU
%Ts=8*10^-6; %Fs = 125kHz of PWM defined on the PIC to the gate driver
tcntrl=8*10^-6;
Ts=8*10^-6;

Tdpwm=D*Ts;
td=tcntrl+Tdpwm;
Nr=1;
fs=1/Ts;
sample_time=Ts;

%plant arrays for D and D`
A1 = [ -(rC+rL)/L -1/L; 1/C 0 ];
A0 = A1;
b1 = [ 1/L rC/L; 0 -1/C ];
b0 = [ 0 rC/L; 0 -1/C];
c1 = [1 0; rC 1];
c0 = c1;


%Discretizasción del sistema y obtención de FT de V e I, mediante el metodo de WILEY
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

%Obtención de la FT discretizada mediante el método de impulso 
Gids = Vg*(s*C)/(1+s*rC*C+s*C);
%Xdown = ((eye(2)-exL+rC)*C+s^2*L*C);
Gids.outputdelay = td;
Giuz2 = (1/Nr)*c2d(Gids,Ts,'imp');


% Target crossover frequency and phase margin
wc = 2*pi*(fs/10);
mphi = (pi/180)*77; % 45deg to radians

% Magnitude and phase of Tuz at the target crossover frequency
[m,p0] = bode(Giuz,wc);
%m=63*10^-3;
%p=-199;
p = (pi/180)*p0;

% Prewarping on wc
wcp = (2/Ts)*tan(wc*Ts/2);

% PD Design
wp = 2*pi*fs/pi;
pw = atan(wcp/wp);

% PI zero and high-frequency gain
wPI = wcp*tan(87.04-77);
GPIinf = (1/m)*(1/sqrt(1+(wPI/wcp)^2));

% Proportional, Integral and Derivative Gains
Kp = GPIinf*(1+wPI/wp);
Ki = 2*GPIinf*wPI/wp;


% PID Transfer function
z = tf('z',Ts);
Gcz = Kp + Ki/(1-z^-1);

display(Giuz)
display(Gcz)
display(Kp)
display(Ki)
display(m)
display(p0)
bode(Giuz2,Giuz)
%bode(p0)
%bode(Giuz2,Giuz)

