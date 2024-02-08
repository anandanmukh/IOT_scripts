ScrewDiameter=2.4;
GpsHolderDiameter=4;        
DistanceBetweenScrews=36;  

$fn=20;
A=DistanceBetweenScrews+ScrewDiameter;
difference () {
    cylinder (h=GpsHolderDiameter*5,d=GpsHolderDiameter+4);
    
    translate ([0,0,2]) cylinder (h=(GpsHolderDiameter*5)+2,d=GpsHolderDiameter+0.2);
}

difference () {
union () {
translate ([-(ScrewDiameter+5)/2,-A/2,0]) cube ([ScrewDiameter+5,A,2.5]);
    
translate ([0,A/2,0]) cylinder (h=2.5,d=ScrewDiameter+5);
    
translate ([0,-A/2]) cylinder (h=2.5,d=ScrewDiameter+5);
}

translate ([0,A/2,-0.1]) cylinder (h=3,d=ScrewDiameter+0.1);

translate ([0,-A/2,-0.1]) cylinder (h=3,d=ScrewDiameter+0.1);
}


cylinder (h=2.5,d=GpsHolderDiameter+6);

difference () {
    translate([-GpsHolderDiameter*0.3750,0,0]) rotate([0,90,0])cylinder(d=DistanceBetweenScrews-ScrewDiameter, h=GpsHolderDiameter*0.75);
    translate ([0,0,2]) cylinder (h=(GpsHolderDiameter*5)+2,d=GpsHolderDiameter+0.2);
    
    translate([-GpsHolderDiameter,-DistanceBetweenScrews/2,-(DistanceBetweenScrews-ScrewDiameter)/2])cube([GpsHolderDiameter*2,DistanceBetweenScrews,(DistanceBetweenScrews-ScrewDiameter+0.5)/2]);
}