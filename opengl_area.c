#include <math.h>
#include <gtk/gtk.h>
#include <epoxy/gl.h>

static GtkWidget *demo_window = NULL; 

static GtkWidget *gl_area = NULL; 

enum {
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
	
	N_AXIS
};

/* rotation angles on each axis */
static float rotation_angles [N_AXIS] = { 0.0 };

/* triangle object drawn */
static const GLfloat vertex_data[] = {
	0.f, 0.5f, 0.f, 1.f,
  0.5f, -0.366f, 0.f, 1.f,
 -0.5f, -0.366f, 0.f, 1.f, 
};

/* initialize GL buffers */
static void init_buffers ( GLuint *vao_out, GLuint *buffer_out) 
{
	GLuint vao, buffer;
	
	glGenVertexarrays (1, &buffer);
	glBindBuffer (GL_ARRAY_BUFFER, buffer);
	glBufferData (GL_ARRAY_BUFFER, sizeof (vertex_data), GL_STATIC_DRAW);
	glBindBuffer (GL_ARRAY_BUFFER, 0); 

if (vao_out != NULL)
    *vao_out = vao;

if (buffer_out != NULL) 
    *buffer_out = buffer; 

}

/* create and compile shader */
static GLuint
create_shader (int type, const char *src) {

	GLuint shader;
	int status; 

	shader = glCreateShader (type); 
	glShaderSource(shader, 1, &src, NULL); 
	glCompileShader (shader); 

	glGetShaderiv (shader GL_COMPILE_STATUS, &status); 
	if (status == GL_FALSE)
	{
		int log_len; 
		char *buffer; 
	}
}
