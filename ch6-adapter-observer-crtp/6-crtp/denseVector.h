template <typename ActualVector>
class DenseVector
{
// public:
//   using value_type = typename ActualVector::value_type;
//   using iterator = typename ActualVector::iterator;
//   using const_iterator = typename ActualVector::const_iterator;

public:
  ActualVector        &vector()       { return static_cast<ActualVector &>(*this); }
  const ActualVector  &vector() const { return static_cast<const ActualVector &>(*this); }

  decltype(auto)        operator[](std::size_t index)       { return vector()[index]; }
  decltype(auto) operator[](std::size_t index) const { return vector()[index]; }

  decltype(auto) begin()       { return vector().begin(); }
  decltype(auto) begin() const { return vector().begin(); }
  decltype(auto) end()         { return vector().end(); }
  decltype(auto) end()   const { return vector().end(); }

  std::size_t size() const { return vector().size(); }

protected:
  ~DenseVector() = default;
};
