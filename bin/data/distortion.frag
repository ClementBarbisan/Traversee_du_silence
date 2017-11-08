#version 150

//uniform sampler2DRect displacement2;
uniform float timeOutRandom;
uniform float time;
uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

float rand(vec2 co)
{
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
	vec2 pos = vec2(rand(vec2(texCoordVarying.y, time)), rand(vec2(texCoordVarying.x, time))) * 10;
	vec2 where = (texCoordVarying-pos * timeOutRandom);
	vec4 texchur1 = texture(tex0,vec2(where.x,where.y));
	float max = max(texchur1.x, max(texchur1.y, texchur1.z));
	if (max <= 0 || max > 0.02)
		texchur1 = vec4(1, 1, 1, 1);
	else
		texchur1 = vec4(0, 0, 0, 1);
    outputColor = texchur1;
}