function [IdNearestNonCrossingNeighbour,distance] = findNearestNonCrossingNeighbour(fieldWidth,startPoint,vertex,availableVertices)
%Znajduje najbli�szego s�siada obecnego wierzcho�ka z dost�pnej puli, kt�ry
%nie generuje skrzy�owa�
%je�eli nie ma to zwraca -1

IdNearestNonCrossingNeighbour = -1;
minimumDistance = 9999999999999;

for i=1:size(availableVertices,1);
    neighbour = availableVertices(i,:);
    distance = sqrt(power(abs(vertex(2)-neighbour(2)),2)+power(abs(vertex(3)-neighbour(3)),2));
    nonCrossing = crossCanOccur(fieldWidth,vertex,neighbour,startPoint,availableVertices) == false;
    if (distance<minimumDistance) && nonCrossing
        IdNearestNonCrossingNeighbour = neighbour(1);
        minimumDistance = distance;
    end; 
end;
return
end

