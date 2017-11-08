#version 150

uniform float timeOutRandom;
uniform float timeOut;
uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{
	vec4 texchur1 = texture(tex0,texCoordVarying);
	float max = max(texchur1.x, max(texchur1.y, texchur1.z));
	if (max <= 0 || max > 0.02)
		texchur1 = vec4(1, 1, 1, 1);
	else
		texchur1 = vec4(0, 0, 0, 1);
    outputColor = vec4(texchur1.xyz, clamp(timeOutRandom - 0.5 - timeOut, 0, 1));
}