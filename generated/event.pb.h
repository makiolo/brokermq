// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_event_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_event_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_event_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_event_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_event_2eproto;
namespace zeromq_project {
namespace proto {
class Mutation;
struct MutationDefaultTypeInternal;
extern MutationDefaultTypeInternal _Mutation_default_instance_;
class Mutation_MetadataEntry_DoNotUse;
struct Mutation_MetadataEntry_DoNotUseDefaultTypeInternal;
extern Mutation_MetadataEntry_DoNotUseDefaultTypeInternal _Mutation_MetadataEntry_DoNotUse_default_instance_;
class Response;
struct ResponseDefaultTypeInternal;
extern ResponseDefaultTypeInternal _Response_default_instance_;
}  // namespace proto
}  // namespace zeromq_project
PROTOBUF_NAMESPACE_OPEN
template<> ::zeromq_project::proto::Mutation* Arena::CreateMaybeMessage<::zeromq_project::proto::Mutation>(Arena*);
template<> ::zeromq_project::proto::Mutation_MetadataEntry_DoNotUse* Arena::CreateMaybeMessage<::zeromq_project::proto::Mutation_MetadataEntry_DoNotUse>(Arena*);
template<> ::zeromq_project::proto::Response* Arena::CreateMaybeMessage<::zeromq_project::proto::Response>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace zeromq_project {
namespace proto {

// ===================================================================

class Mutation_MetadataEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Mutation_MetadataEntry_DoNotUse, 
    std::string, std::string,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING> {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Mutation_MetadataEntry_DoNotUse, 
    std::string, std::string,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING> SuperType;
  Mutation_MetadataEntry_DoNotUse();
  explicit PROTOBUF_CONSTEXPR Mutation_MetadataEntry_DoNotUse(
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);
  explicit Mutation_MetadataEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const Mutation_MetadataEntry_DoNotUse& other);
  static const Mutation_MetadataEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const Mutation_MetadataEntry_DoNotUse*>(&_Mutation_MetadataEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), static_cast<int>(s->size()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "zeromq_project.proto.Mutation.MetadataEntry.key");
 }
  static bool ValidateValue(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), static_cast<int>(s->size()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "zeromq_project.proto.Mutation.MetadataEntry.value");
 }
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  friend struct ::TableStruct_event_2eproto;
};

// -------------------------------------------------------------------

class Mutation final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:zeromq_project.proto.Mutation) */ {
 public:
  inline Mutation() : Mutation(nullptr) {}
  ~Mutation() override;
  explicit PROTOBUF_CONSTEXPR Mutation(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Mutation(const Mutation& from);
  Mutation(Mutation&& from) noexcept
    : Mutation() {
    *this = ::std::move(from);
  }

  inline Mutation& operator=(const Mutation& from) {
    CopyFrom(from);
    return *this;
  }
  inline Mutation& operator=(Mutation&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Mutation& default_instance() {
    return *internal_default_instance();
  }
  static inline const Mutation* internal_default_instance() {
    return reinterpret_cast<const Mutation*>(
               &_Mutation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Mutation& a, Mutation& b) {
    a.Swap(&b);
  }
  inline void Swap(Mutation* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Mutation* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Mutation* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Mutation>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Mutation& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Mutation& from) {
    Mutation::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Mutation* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "zeromq_project.proto.Mutation";
  }
  protected:
  explicit Mutation(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kMetadataFieldNumber = 8,
    kNameFieldNumber = 2,
    kOriginFieldNumber = 3,
    kDestinationFieldNumber = 4,
    kIdFieldNumber = 1,
    kAgeFieldNumber = 5,
    kYearFieldNumber = 6,
    kYear2FieldNumber = 7,
  };
  // map<string, string> metadata = 8;
  int metadata_size() const;
  private:
  int _internal_metadata_size() const;
  public:
  void clear_metadata();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >&
      _internal_metadata() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >*
      _internal_mutable_metadata();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >&
      metadata() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >*
      mutable_metadata();

  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string origin = 3;
  void clear_origin();
  const std::string& origin() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_origin(ArgT0&& arg0, ArgT... args);
  std::string* mutable_origin();
  PROTOBUF_NODISCARD std::string* release_origin();
  void set_allocated_origin(std::string* origin);
  private:
  const std::string& _internal_origin() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_origin(const std::string& value);
  std::string* _internal_mutable_origin();
  public:

  // string destination = 4;
  void clear_destination();
  const std::string& destination() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_destination(ArgT0&& arg0, ArgT... args);
  std::string* mutable_destination();
  PROTOBUF_NODISCARD std::string* release_destination();
  void set_allocated_destination(std::string* destination);
  private:
  const std::string& _internal_destination() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_destination(const std::string& value);
  std::string* _internal_mutable_destination();
  public:

  // int32 id = 1;
  void clear_id();
  int32_t id() const;
  void set_id(int32_t value);
  private:
  int32_t _internal_id() const;
  void _internal_set_id(int32_t value);
  public:

  // int32 age = 5;
  void clear_age();
  int32_t age() const;
  void set_age(int32_t value);
  private:
  int32_t _internal_age() const;
  void _internal_set_age(int32_t value);
  public:

  // int32 year = 6;
  void clear_year();
  int32_t year() const;
  void set_year(int32_t value);
  private:
  int32_t _internal_year() const;
  void _internal_set_year(int32_t value);
  public:

  // int32 year2 = 7;
  void clear_year2();
  int32_t year2() const;
  void set_year2(int32_t value);
  private:
  int32_t _internal_year2() const;
  void _internal_set_year2(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:zeromq_project.proto.Mutation)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::MapField<
        Mutation_MetadataEntry_DoNotUse,
        std::string, std::string,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING> metadata_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr origin_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr destination_;
    int32_t id_;
    int32_t age_;
    int32_t year_;
    int32_t year2_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_event_2eproto;
};
// -------------------------------------------------------------------

class Response final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:zeromq_project.proto.Response) */ {
 public:
  inline Response() : Response(nullptr) {}
  ~Response() override;
  explicit PROTOBUF_CONSTEXPR Response(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Response(const Response& from);
  Response(Response&& from) noexcept
    : Response() {
    *this = ::std::move(from);
  }

  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }
  inline Response& operator=(Response&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Response& default_instance() {
    return *internal_default_instance();
  }
  static inline const Response* internal_default_instance() {
    return reinterpret_cast<const Response*>(
               &_Response_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Response& a, Response& b) {
    a.Swap(&b);
  }
  inline void Swap(Response* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Response* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Response* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Response>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Response& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Response& from) {
    Response::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Response* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "zeromq_project.proto.Response";
  }
  protected:
  explicit Response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBodyFieldNumber = 2,
    kCodeFieldNumber = 1,
    kAgeFieldNumber = 3,
  };
  // string body = 2;
  void clear_body();
  const std::string& body() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_body(ArgT0&& arg0, ArgT... args);
  std::string* mutable_body();
  PROTOBUF_NODISCARD std::string* release_body();
  void set_allocated_body(std::string* body);
  private:
  const std::string& _internal_body() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_body(const std::string& value);
  std::string* _internal_mutable_body();
  public:

  // int32 code = 1;
  void clear_code();
  int32_t code() const;
  void set_code(int32_t value);
  private:
  int32_t _internal_code() const;
  void _internal_set_code(int32_t value);
  public:

  // int32 age = 3;
  void clear_age();
  int32_t age() const;
  void set_age(int32_t value);
  private:
  int32_t _internal_age() const;
  void _internal_set_age(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:zeromq_project.proto.Response)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr body_;
    int32_t code_;
    int32_t age_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_event_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Mutation

// int32 id = 1;
inline void Mutation::clear_id() {
  _impl_.id_ = 0;
}
inline int32_t Mutation::_internal_id() const {
  return _impl_.id_;
}
inline int32_t Mutation::id() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.id)
  return _internal_id();
}
inline void Mutation::_internal_set_id(int32_t value) {
  
  _impl_.id_ = value;
}
inline void Mutation::set_id(int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.id)
}

// string name = 2;
inline void Mutation::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Mutation::name() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Mutation::set_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.name)
}
inline std::string* Mutation::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:zeromq_project.proto.Mutation.name)
  return _s;
}
inline const std::string& Mutation::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Mutation::_internal_set_name(const std::string& value) {
  
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Mutation::_internal_mutable_name() {
  
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* Mutation::release_name() {
  // @@protoc_insertion_point(field_release:zeromq_project.proto.Mutation.name)
  return _impl_.name_.Release();
}
inline void Mutation::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:zeromq_project.proto.Mutation.name)
}

// string origin = 3;
inline void Mutation::clear_origin() {
  _impl_.origin_.ClearToEmpty();
}
inline const std::string& Mutation::origin() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.origin)
  return _internal_origin();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Mutation::set_origin(ArgT0&& arg0, ArgT... args) {
 
 _impl_.origin_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.origin)
}
inline std::string* Mutation::mutable_origin() {
  std::string* _s = _internal_mutable_origin();
  // @@protoc_insertion_point(field_mutable:zeromq_project.proto.Mutation.origin)
  return _s;
}
inline const std::string& Mutation::_internal_origin() const {
  return _impl_.origin_.Get();
}
inline void Mutation::_internal_set_origin(const std::string& value) {
  
  _impl_.origin_.Set(value, GetArenaForAllocation());
}
inline std::string* Mutation::_internal_mutable_origin() {
  
  return _impl_.origin_.Mutable(GetArenaForAllocation());
}
inline std::string* Mutation::release_origin() {
  // @@protoc_insertion_point(field_release:zeromq_project.proto.Mutation.origin)
  return _impl_.origin_.Release();
}
inline void Mutation::set_allocated_origin(std::string* origin) {
  if (origin != nullptr) {
    
  } else {
    
  }
  _impl_.origin_.SetAllocated(origin, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.origin_.IsDefault()) {
    _impl_.origin_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:zeromq_project.proto.Mutation.origin)
}

// string destination = 4;
inline void Mutation::clear_destination() {
  _impl_.destination_.ClearToEmpty();
}
inline const std::string& Mutation::destination() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.destination)
  return _internal_destination();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Mutation::set_destination(ArgT0&& arg0, ArgT... args) {
 
 _impl_.destination_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.destination)
}
inline std::string* Mutation::mutable_destination() {
  std::string* _s = _internal_mutable_destination();
  // @@protoc_insertion_point(field_mutable:zeromq_project.proto.Mutation.destination)
  return _s;
}
inline const std::string& Mutation::_internal_destination() const {
  return _impl_.destination_.Get();
}
inline void Mutation::_internal_set_destination(const std::string& value) {
  
  _impl_.destination_.Set(value, GetArenaForAllocation());
}
inline std::string* Mutation::_internal_mutable_destination() {
  
  return _impl_.destination_.Mutable(GetArenaForAllocation());
}
inline std::string* Mutation::release_destination() {
  // @@protoc_insertion_point(field_release:zeromq_project.proto.Mutation.destination)
  return _impl_.destination_.Release();
}
inline void Mutation::set_allocated_destination(std::string* destination) {
  if (destination != nullptr) {
    
  } else {
    
  }
  _impl_.destination_.SetAllocated(destination, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.destination_.IsDefault()) {
    _impl_.destination_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:zeromq_project.proto.Mutation.destination)
}

// int32 age = 5;
inline void Mutation::clear_age() {
  _impl_.age_ = 0;
}
inline int32_t Mutation::_internal_age() const {
  return _impl_.age_;
}
inline int32_t Mutation::age() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.age)
  return _internal_age();
}
inline void Mutation::_internal_set_age(int32_t value) {
  
  _impl_.age_ = value;
}
inline void Mutation::set_age(int32_t value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.age)
}

// int32 year = 6;
inline void Mutation::clear_year() {
  _impl_.year_ = 0;
}
inline int32_t Mutation::_internal_year() const {
  return _impl_.year_;
}
inline int32_t Mutation::year() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.year)
  return _internal_year();
}
inline void Mutation::_internal_set_year(int32_t value) {
  
  _impl_.year_ = value;
}
inline void Mutation::set_year(int32_t value) {
  _internal_set_year(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.year)
}

// int32 year2 = 7;
inline void Mutation::clear_year2() {
  _impl_.year2_ = 0;
}
inline int32_t Mutation::_internal_year2() const {
  return _impl_.year2_;
}
inline int32_t Mutation::year2() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Mutation.year2)
  return _internal_year2();
}
inline void Mutation::_internal_set_year2(int32_t value) {
  
  _impl_.year2_ = value;
}
inline void Mutation::set_year2(int32_t value) {
  _internal_set_year2(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Mutation.year2)
}

// map<string, string> metadata = 8;
inline int Mutation::_internal_metadata_size() const {
  return _impl_.metadata_.size();
}
inline int Mutation::metadata_size() const {
  return _internal_metadata_size();
}
inline void Mutation::clear_metadata() {
  _impl_.metadata_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >&
Mutation::_internal_metadata() const {
  return _impl_.metadata_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >&
Mutation::metadata() const {
  // @@protoc_insertion_point(field_map:zeromq_project.proto.Mutation.metadata)
  return _internal_metadata();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >*
Mutation::_internal_mutable_metadata() {
  return _impl_.metadata_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >*
Mutation::mutable_metadata() {
  // @@protoc_insertion_point(field_mutable_map:zeromq_project.proto.Mutation.metadata)
  return _internal_mutable_metadata();
}

// -------------------------------------------------------------------

// Response

// int32 code = 1;
inline void Response::clear_code() {
  _impl_.code_ = 0;
}
inline int32_t Response::_internal_code() const {
  return _impl_.code_;
}
inline int32_t Response::code() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Response.code)
  return _internal_code();
}
inline void Response::_internal_set_code(int32_t value) {
  
  _impl_.code_ = value;
}
inline void Response::set_code(int32_t value) {
  _internal_set_code(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Response.code)
}

// string body = 2;
inline void Response::clear_body() {
  _impl_.body_.ClearToEmpty();
}
inline const std::string& Response::body() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Response.body)
  return _internal_body();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Response::set_body(ArgT0&& arg0, ArgT... args) {
 
 _impl_.body_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Response.body)
}
inline std::string* Response::mutable_body() {
  std::string* _s = _internal_mutable_body();
  // @@protoc_insertion_point(field_mutable:zeromq_project.proto.Response.body)
  return _s;
}
inline const std::string& Response::_internal_body() const {
  return _impl_.body_.Get();
}
inline void Response::_internal_set_body(const std::string& value) {
  
  _impl_.body_.Set(value, GetArenaForAllocation());
}
inline std::string* Response::_internal_mutable_body() {
  
  return _impl_.body_.Mutable(GetArenaForAllocation());
}
inline std::string* Response::release_body() {
  // @@protoc_insertion_point(field_release:zeromq_project.proto.Response.body)
  return _impl_.body_.Release();
}
inline void Response::set_allocated_body(std::string* body) {
  if (body != nullptr) {
    
  } else {
    
  }
  _impl_.body_.SetAllocated(body, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.body_.IsDefault()) {
    _impl_.body_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:zeromq_project.proto.Response.body)
}

// int32 age = 3;
inline void Response::clear_age() {
  _impl_.age_ = 0;
}
inline int32_t Response::_internal_age() const {
  return _impl_.age_;
}
inline int32_t Response::age() const {
  // @@protoc_insertion_point(field_get:zeromq_project.proto.Response.age)
  return _internal_age();
}
inline void Response::_internal_set_age(int32_t value) {
  
  _impl_.age_ = value;
}
inline void Response::set_age(int32_t value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:zeromq_project.proto.Response.age)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace zeromq_project

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_event_2eproto
