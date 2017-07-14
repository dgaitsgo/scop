#version 410

	//Defines:
const uint		mode_greyScale = 0;
const uint		mode_normalMapping = 1;

	//Uniforms
uniform float		fade;

	//Ins
in	vec3 			fNormal;
in	vec4			fPositions;
in	vec4			positionWorldSpace;
flat in int			render_mode;

	//Texture
vec4				texel;
vec2				text_coords;
uniform sampler2D	basic_texture;

	//Lighting
struct		s_light
{
	vec3 	origin;
	vec3 	direction;
	vec3	color;
}			t_light;


float lambertCoeff = 0.6f;
float specularCoeff = 0.1f;
vec4				color;

//Out
out vec4			frag_color;

//___________________________________________//

float		map(float value, float low1, float high1, float low2, float high2)
{
	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}

vec4		lambert_shading(vec4 color, s_light light)
{
	vec3 inter = normalize(light.origin - positionWorldSpace.xyz);
	float lambertAmt = dot(inter, fNormal);
	vec4 temp = lambertCoeff * color * lambertAmt;
	return (temp);
}

vec4		specular_shading(vec4 color, s_light light)
{
	vec3 l = normalize(light.origin - positionWorldSpace.xyz);
	vec3 r = l + (-2 * fNormal * dot(l, fNormal));
	float dot = dot(light.direction, r);
	float spec = 0;
	if (dot > 0)
		spec = pow(dot, 20) * specularCoeff;
	vec4 temp = color * spec;
	return (temp);
}


void		 main ()
{
	s_light		light;

	light.origin = vec3(30, 30, 30);
	light.direction = normalize(vec3(0, -20, 1));
	light.color = vec3(.3, .3, .3);

	text_coords.x = map(fPositions.x, -1, 1, 0, 1);
	text_coords.y = map(fPositions.y, -1, 1, 0, 1);
	texel = texture(basic_texture, text_coords); 

	if (render_mode == mode_greyScale)
		color = vec4(.4, .4, .4, 1.0);
	else if (render_mode == mode_normalMapping)
		color = vec4 (fNormal, 1.0);

	color = mix(color, texel, fade);
	frag_color = color + specular_shading(color, light) + lambert_shading(color, light);
}
