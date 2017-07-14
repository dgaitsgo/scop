#version 410

in 	vec3 		position;

uniform float 	modelBVRadius;
uniform int		instanceLen;	

out vData {
	int		render_mode;
	vec4	raw_pos;
}	vertex;

uniform int render_mode;

void	main()
{
	float diam = modelBVRadius * 2;
	vertex.raw_pos = vec4(position, 1.0);
	vertex.render_mode = render_mode;
	gl_Position = vertex.raw_pos + vec4((gl_InstanceID % instanceLen) * diam, 0, (gl_InstanceID / instanceLen) * diam ,0);
}
