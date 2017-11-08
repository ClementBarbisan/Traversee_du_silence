#version 150

uniform sampler2DRect displacement;
//uniform sampler2DRect displacement2;
uniform float timeOut;
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
	vec2 pos = vec2(rand(vec2(texCoordVarying.y, time)), rand(vec2(texCoordVarying.x, time)));
	vec2 uv = texture(displacement, texCoordVarying).xz;
	//vec2 uv2 = texture(displacement2, texCoordVarying).xz;
    //outputColor = texture(tex0, texCoordVarying + ((uv + uv2 / 20) * 200));
	vec4 texchur1 = texture(tex0, texCoordVarying + ((uv * 200 * timeOut + pos * 40 * timeOutRandom) ));
	float max = max(texchur1.x, max(texchur1.y, texchur1.z));
	if (max > 0.8)
		texchur1 = vec4(1, 1, 1, 0);
	else
		texchur1 = vec4(0.01, 0.01, 0.01, 1);
    outputColor = texchur1;
}