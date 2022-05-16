% @file math_model.m
% @author Kevin Gomez Villagra
% @date 17 Feb 2022
% @brief definitions for the mathematical model of the BDC prototype controller.
% @par Institution:
% Costa Rica Institute of Technology.
% @par Mail:
% kevinxnor1419@estudiantec.cr

clc
clear all 
s = tf('s');

%variables
rC=0.8*10^-3;
rL=43*10^-3;
L=22*10^-6;
C=34*10^-6;

Vg=4.8;
Io=3;
D=0.5;
Dprime=1-D;

tcntrl=9*10^-6;
Ts=8*10^-6; %Fs = 125kHz

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

%Gvd=(Vg*(1+7.5*10^-6*s))/(30*10^-6*s^2+2.1*10^-5*s+1);

