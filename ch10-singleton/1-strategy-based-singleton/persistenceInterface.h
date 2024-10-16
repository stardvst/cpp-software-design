class PersistenceInterface
{
public:
  virtual ~PersistenceInterface() = default;

  bool read() const
  {
    return do_read();
  }

  bool write()
  {
    return do_write();
  }

private:
  virtual bool do_read() const = 0;
  virtual bool do_write() = 0;
};

PersistenceInterface *get_persistence_interface();
void set_persistence_interface(PersistenceInterface *);

extern PersistenceInterface *interface;
