#version 120

void main(){
	//gl_FragCoord gives us the x and y of the current pixel its drawing
	float xVal = gl_FragCoord.x;
	float yVal = gl_FragCoord.y;
	
	//we use the mod function to only draw pixels if they are every 1 in x or every 2 in y
    if( mod(xVal, 1.0) == 0.5 && mod(yVal, 2.0) == 0.5 ){
        gl_FragColor = gl_Color;    
    }else{
        gl_FragColor.a = 0.0;
    }
}