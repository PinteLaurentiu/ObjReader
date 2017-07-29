class OBJParser;

class Model {
private:
    class Mesh;
    Model();
    friend class OBJParser;
    Mesh* meshes;
public:
    virtual ~Model();
    const Mesh* begin();
    const Mesh* end();
    std::vector<Mesh> getMeshes();
};


class Model::Mesh {
private:
    
};
