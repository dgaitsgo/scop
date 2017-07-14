#ifndef __MODEL_H
# define __MODEL_H

#include "vector.h"
#include "open_gl.h"
#include "texture.h"

enum			e_flags
{
	NEGATIVE_INDEXES,
	ONLY_GEOMETRY,
	ALL_VERTS_DEFINED,
	TEXT_COORDS_DEFINED,
	NORMALS_DEFINED,
	MTL_ASSOCIATED,
	MULTIPLE_OBJECTS,
};

enum						e_model_indices
{
	VERTEX,
	NORMAL,
	TEXTURE,
};

typedef struct				s_mtl
{
	t_texture_lst			*textures;
}							t_mtl;

typedef struct				s_bounding_sphere
{
	t_vector				min;
	t_vector				max;
	t_vector				center;
	float					diameter;
}							t_bounding_sphere;

//should be called meta
typedef	struct				s_group_lst
{
	int						quads;
	int						n_vertices;
	int						n_text_coords;
	int						n_normals;
	int						n_faces;
	struct s_group_lst		*next;
}							t_group_lst;

typedef	struct				s_shader_state
{
	int						smooth_shading;
	char					*mtl;
	int						beg;
	int						end;
	struct s_shader_state	*next;
}							t_shader_state;

typedef	struct				s_vertex_table
{
	int						i_pos;
	int						i_text;
	int						i_norm;
	float					*positions;
	float					*text_coords;
	float					*normals;
}							t_vertex_table;

typedef struct				s_obj_data
{
//	t_shader_state			*shdr_state;
	int						quads;

	t_vector				*vertices;
	t_vector				*text_coords;
	t_vector				*normals;

	int						*vert_indices;
	int						*text_indices;
	int						*norm_indices;

	int						n_vertices;
	int						n_text_coords;
	int						n_normals;

	int						n_faces;
	int						n_vert_indices;
	int						n_text_indices;
	int						n_norm_indices;
}							t_obj_data;

typedef struct				s_model
{
	// missing reference to mtl file
	int						flags;
	int						n_groups;
	t_matrix				model;
	t_matrix				offset;
	t_group_lst				*root_group;
	t_obj_data				**obj_data;
	t_vertex_table			*vertex_table;
	t_bounding_sphere		bv;
	GLuint					vao;
}							t_model;

void						bound_model(t_model *model);
struct s_group_lst			*new_group(void);
void						init_model(t_model *model);

#endif
