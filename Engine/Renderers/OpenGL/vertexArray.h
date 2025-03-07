class VertexArray
{
private:
	unsigned int mVerticeCount;
	unsigned int mIndexCount;
	unsigned int mVertexArrayId;
	unsigned int mVertexBufferId;
	unsigned int mIndexBufferId;
	unsigned int mVboId;

public:
	VertexArray(const float* pVertices, unsigned int pVerticeCount, const unsigned int* pIndices, unsigned int pIndexCount);
	~VertexArray();

	void SetActive();
	unsigned int GetVerticeCount() const { return mVerticeCount; }
	unsigned int GetIndicesCount() const { return mIndexCount; }
};

constexpr float vertices[] = {
-0.5f, 0.5f, 0.0f,		0.0f, 0.0f,		// TOP		LEFT
0.5f, 0.5f, 0.0f,		1.0f, 0.0f,		// TOP		RIGHT
0.5f, -0.5f, 0.0f,		1.0f, 1.0f,		// BOTTOM	RIGHT
-0.5f, -0.5f, 0.0f,		0.0f, 1.0f };	// BOTTOM	LEFT

constexpr unsigned int indices[] = {
0, 1, 2,
2, 3, 0
};
