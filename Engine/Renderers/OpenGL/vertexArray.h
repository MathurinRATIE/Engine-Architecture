class VertexArray
{
private:
	unsigned int mVerticeCount;
	unsigned int mVertexArrayId;
	unsigned int mVertexBufferId;

public:
	VertexArray(const float* pVertices, unsigned int pVerticeCount);
	~VertexArray();

	void SetActive();
	unsigned int GetVerticeCount() const { return mVerticeCount; }
};