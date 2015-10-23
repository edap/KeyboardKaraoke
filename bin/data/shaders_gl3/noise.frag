#version 150

uniform sampler2D src_tex_unit0;
uniform vec4 globalColor;

in vec2 texCoordVarying;

out vec4 fragColor;

void main(){
	//gl_FragCoord gives us the x and y of the current pixel its drawing
	float xVal = gl_FragCoord.x;
	float yVal = gl_FragCoord.y;
    
	//we use the mod function to only draw pixels if they are every 2 in x or every 4 in y
	if( mod(xVal, 1.0) == 0.5 && mod(yVal, 2.0) == 0.5 ){
		fragColor = globalColor;    
    }else{
		discard;
	}
}
