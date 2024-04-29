class JSONExportable
{
public:
  virtual ~JSONExportable() = default;

  virtual void exportToJSON(/* args */) const = 0;
};

class Serializeable
{
public:
  virtual ~Serializeable() = default;

  virtual void serialize(/* args */) const = 0;
};

class Document
    : public JSONExportable,
      public Serializeable
{
};
