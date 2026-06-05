#include "glbasimac/glbi_convex_2D_shape.hpp"
#include <array>

namespace glbasimac {

	void GLBI_Convex_2D_Shape::initShape(std::vector<float> in_coord) {
		coord_pts.clear();
		nml_pts.clear();
		if (dimension == 2) {
			assert(in_coord.size()%2 == 0);
			nb_pts = in_coord.size()/2;
		}
		else {
			assert(in_coord.size()%3 == 0);
			nb_pts = in_coord.size()/3;
			//std::cerr<<"NB POINT : "<<nb_pts<<std::endl;
		}

		shape.setNbElt(nb_pts);
		coord_pts = std::move(in_coord);
		shape.addOneBuffer(0,dimension,coord_pts.data(),"Coordinates",false);
		// Added normals too 2D Shapes
        nml_pts.resize(3 * nb_pts);

        for (int i = 0; i < nb_pts; ++i) {
            nml_pts[3 * i + 0] = 0.f;
            nml_pts[3 * i + 1] = 0.f;
            nml_pts[3 * i + 2] = 1.f;
        }

        shape.addOneBuffer(1, 3,
                        nml_pts.data(),
                        "Normals",
                        false);

		if(!shape.createVAO()) {
			std::cerr<<"Unable to create VAO for Set of Points"<<std::endl;
			exit(1);
		}
	}

	void GLBI_Convex_2D_Shape::changeNature(unsigned int new_gl_type) {
		shape.changeType(new_gl_type);
	}

	void GLBI_Convex_2D_Shape::drawShape() {
		shape.draw();
	}

}
