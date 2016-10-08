%line1
x1  = [-3 3];
y1  = [-3 3];

%line2
x2 = [-2 2];
y2 = [-3 3];

%fit linear polynomial
p1 = polyfit(x1,y1,1);
p2 = polyfit(x2,y2,1);

%calculate intersection
x_intersect = fzero(@(x) polyval(p1-p2,x),3);
y_intersect = polyval(p1,x_intersect);

line(x1,y1);
hold on;
line(x2,y2);
plot(x_intersect,y_intersect,'r*')
disp(x_intersect);
disp(y_intersect);
