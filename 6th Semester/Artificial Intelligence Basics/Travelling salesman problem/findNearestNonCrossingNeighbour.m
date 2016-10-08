function [IdNearestNonCrossingNeighbour,distance] = findNearestNonCrossingNeighbour(fieldWidth,startPoint,vertex,availableVertices)
%Znajduje najbli¿szego s¹siada obecnego wierzcho³ka z dostêpnej puli, który
%nie generuje skrzy¿owañ
%je¿eli nie ma to zwraca -1

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

