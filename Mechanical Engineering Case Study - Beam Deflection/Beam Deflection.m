%This program aims to calculate the beam deflection with multiple provided
%values, and plot its corresponding x-V graph.
fprintf('Welcome to the program, this program performs: \n');
fprintf('1) Calculation of beam deflection at x and graph plotting \n');
fprintf('2) Plot the graph of beam deflection \n');
ctr=input('Please make your selection: \n');
%check the validity of menu selection
while ctr>2||ctr<1
    ctr=input('Your input is invalid, please make your selection: \n');
end

L=input('Please enter the length of the beam: \n');
%the length of the beam cannot be negative
while L<0
    L=input('Your input is invalid, please enter a valid length of the beam: \n');
end
x=input('Please enter the distance from the left end: \n');
%x is only valid if it is between 0 and L
validx=0:0.01:L;
%if the x input is not equal to any number between 0 and L with steps of
%0.01, it is invalid
while ~any(x==validx)
    x=input('Your input is invalid, please enter a valid distance from the left end: \n');
end
%P can be negative which in this case indicates applying the load from down upwards to
%the beam 
P=input('Please enter the load: \n');
a=input('Please enter the location where the load is applied: \n');
%a is only valid if it is between 0 and L
valida=0:0.01:L;
%if the a input is not equal to any number between 0 and L with steps of
%0.01, it is invalid
while ~any(a==valida)
    a=input('Your input is invalid, please enter a valid location of where the load is applied: \n');
end
E=input('Please enter the Youngs modulus of the beam material: \n');
%Youngs modulus cannot be negative
while E<0
    E=input('Your input is invalid, please enter a valid Youngs modulus of the beam material: \n');
end
I=input('Please enter the second moment of area: \n');
%the second moment of area cannot be negative
while I<0
    I=input('Your input is invalid, please enter a valid second moment of area: \n');
end
b=L-a;

%if the user wants to perform both calculation and graph plotting
if(ctr==1)
%x is between 0 and a
if(0<x&&x<a)
    V=((P*b)/(6*E*I*L))*(((-L^2)+(b^2))*x+(x^3));
    fprintf('The calculated deflection at x=%.1f is %.6f\n', x, V);
%x is between a and L
elseif(a<x&&x<L)
    V=((P*b)/(6*E*I*L))*(((-L^2)+(b^2))*x+(x^3)-(L/b)*((x-a)^3));
    fprintf('The calculated deflection at x=%.1f is %.6f\n', x, V);
end
X=(0:0.05:a);
%calculating V for all x values between 0 and a with a step of 0.05
V=((P.*b)/(6.*E.*I.*L)).*(((-L.^2)+(b.^2)).*X+(X.^3)); 
plot(X,V, 'g-*')
%keep this scene and the following graph can be plotted in the same scene,
%thus producing a continuous graph
hold on
%formatting the graph
title('Graph of the Beam Deflection')
xlabel('Length of the beam')
ylabel('Beam deflection')
X=(a:0.05:L);
%calculating V for all x values between a and L with a step of 0.05
V=((P.*b)/(6.*E.*I.*L)).*(((-L.^2)+(b.^2)).*X+(X.^3)-(L./b).*((X-a).^3));
plot(X,V, 'g-*')
hold off
fprintf('Thank you for using the program, goodbye!');
end

%if the user only wants to perform graph plotting
if(ctr==2)
X=(0:0.05:a);
%calculating V for all x values between 0 and a with a step of 0.05
V=((P.*b)/(6.*E.*I.*L)).*(((-L.^2)+(b.^2)).*X+(X.^3)); 
plot(X,V, 'g-*')
%keep this scene and the following graph can be plotted in the same scene,
%thus producing a continuous graph
hold on
%formatting the graph
title('Graph of the Beam Deflection')
xlabel('Length of the beam')
ylabel('Beam deflection')
X=(a:0.05:L);
%calculating V for all x values between a and L with a step of 0.05
V=((P.*b)/(6.*E.*I.*L)).*(((-L.^2)+(b.^2)).*X+(X.^3)-(L./b).*((X-a).^3));
plot(X,V, 'g-*')
hold off
fprintf('The graph has displayed, thank you for using the program, goodbye!');
end







