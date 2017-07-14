#version 410

layout ( triangles ) in;
layout ( triangle_strip, max_vertices = 3 ) out;

in vData {
	int		render_mode;
	vec4	raw_pos;
} vertices[];

uniform float	shrink;
uniform float	explode_factor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat4 offset;

vec3 			temp1;
vec3 			temp2;

vec4			v[3];
vec4			cg;


flat out int	render_mode;
out vec3		fNormal;
out	vec4		fPositions;
out vec4		positionWorldSpace;

void	prepVertex(int i)
{
	fPositions = vertices[i].raw_pos;

	gl_Position = cg + shrink * (v[i] - cg);
	gl_Position = gl_Position + vec4(explode_factor * fNormal, 0.0);
	gl_Position.w = 1.0f;
	gl_Position = proj * view * model * offset * gl_Position;

	positionWorldSpace = gl_Position;

	EmitVertex ();
}
void	main()
{
	v[0] = gl_in[0].gl_Position.xyzw;
	v[1] = gl_in[1].gl_Position.xyzw;
	v[2] = gl_in[2].gl_Position.xyzw;

	render_mode = vertices[0].render_mode;

	cg = (v[0] + v[1] + v[2]) / 3;

	temp1 = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
	temp2 = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;
	fNormal = normalize (cross (temp1, temp2));

	for (int i = 0; i < 3; i++)
	{
		prepVertex(i);
	}
	EndPrimitive ();
}
