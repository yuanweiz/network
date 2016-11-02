// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FileTransfer.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "FileTransfer.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Init_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Init_reflection_ = NULL;
const ::google::protobuf::Descriptor* Trunk_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Trunk_reflection_ = NULL;
const ::google::protobuf::Descriptor* Resume_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Resume_reflection_ = NULL;
const ::google::protobuf::Descriptor* Pause_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Pause_reflection_ = NULL;
const ::google::protobuf::Descriptor* Stop_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Stop_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_FileTransfer_2eproto() {
  protobuf_AddDesc_FileTransfer_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "FileTransfer.proto");
  GOOGLE_CHECK(file != NULL);
  Init_descriptor_ = file->message_type(0);
  static const int Init_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Init, trunksize_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Init, startidx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Init, filename_),
  };
  Init_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Init_descriptor_,
      Init::default_instance_,
      Init_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Init, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Init, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Init));
  Trunk_descriptor_ = file->message_type(1);
  static const int Trunk_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Trunk, data_),
  };
  Trunk_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Trunk_descriptor_,
      Trunk::default_instance_,
      Trunk_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Trunk, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Trunk, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Trunk));
  Resume_descriptor_ = file->message_type(2);
  static const int Resume_offsets_[1] = {
  };
  Resume_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Resume_descriptor_,
      Resume::default_instance_,
      Resume_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Resume, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Resume, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Resume));
  Pause_descriptor_ = file->message_type(3);
  static const int Pause_offsets_[1] = {
  };
  Pause_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Pause_descriptor_,
      Pause::default_instance_,
      Pause_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pause, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Pause, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Pause));
  Stop_descriptor_ = file->message_type(4);
  static const int Stop_offsets_[1] = {
  };
  Stop_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Stop_descriptor_,
      Stop::default_instance_,
      Stop_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stop, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Stop, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Stop));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_FileTransfer_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Init_descriptor_, &Init::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Trunk_descriptor_, &Trunk::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Resume_descriptor_, &Resume::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Pause_descriptor_, &Pause::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Stop_descriptor_, &Stop::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_FileTransfer_2eproto() {
  delete Init::default_instance_;
  delete Init_reflection_;
  delete Trunk::default_instance_;
  delete Trunk_reflection_;
  delete Resume::default_instance_;
  delete Resume_reflection_;
  delete Pause::default_instance_;
  delete Pause_reflection_;
  delete Stop::default_instance_;
  delete Stop_reflection_;
}

void protobuf_AddDesc_FileTransfer_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022FileTransfer.proto\"=\n\004Init\022\021\n\ttrunkSiz"
    "e\030\001 \002(\005\022\020\n\010startIdx\030\002 \002(\005\022\020\n\010filename\030\003 "
    "\002(\t\"\025\n\005Trunk\022\014\n\004data\030\001 \002(\t\"\010\n\006Resume\"\007\n\005"
    "Pause\"\006\n\004Stop", 133);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "FileTransfer.proto", &protobuf_RegisterTypes);
  Init::default_instance_ = new Init();
  Trunk::default_instance_ = new Trunk();
  Resume::default_instance_ = new Resume();
  Pause::default_instance_ = new Pause();
  Stop::default_instance_ = new Stop();
  Init::default_instance_->InitAsDefaultInstance();
  Trunk::default_instance_->InitAsDefaultInstance();
  Resume::default_instance_->InitAsDefaultInstance();
  Pause::default_instance_->InitAsDefaultInstance();
  Stop::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_FileTransfer_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_FileTransfer_2eproto {
  StaticDescriptorInitializer_FileTransfer_2eproto() {
    protobuf_AddDesc_FileTransfer_2eproto();
  }
} static_descriptor_initializer_FileTransfer_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Init::kTrunkSizeFieldNumber;
const int Init::kStartIdxFieldNumber;
const int Init::kFilenameFieldNumber;
#endif  // !_MSC_VER

Init::Init()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Init)
}

void Init::InitAsDefaultInstance() {
}

Init::Init(const Init& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Init)
}

void Init::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  trunksize_ = 0;
  startidx_ = 0;
  filename_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Init::~Init() {
  // @@protoc_insertion_point(destructor:Init)
  SharedDtor();
}

void Init::SharedDtor() {
  if (filename_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete filename_;
  }
  if (this != default_instance_) {
  }
}

void Init::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Init::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Init_descriptor_;
}

const Init& Init::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FileTransfer_2eproto();
  return *default_instance_;
}

Init* Init::default_instance_ = NULL;

Init* Init::New() const {
  return new Init;
}

void Init::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Init*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(trunksize_, startidx_);
    if (has_filename()) {
      if (filename_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        filename_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Init::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Init)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 trunkSize = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &trunksize_)));
          set_has_trunksize();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_startIdx;
        break;
      }

      // required int32 startIdx = 2;
      case 2: {
        if (tag == 16) {
         parse_startIdx:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &startidx_)));
          set_has_startidx();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_filename;
        break;
      }

      // required string filename = 3;
      case 3: {
        if (tag == 26) {
         parse_filename:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_filename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->filename().data(), this->filename().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "filename");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Init)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Init)
  return false;
#undef DO_
}

void Init::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Init)
  // required int32 trunkSize = 1;
  if (has_trunksize()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->trunksize(), output);
  }

  // required int32 startIdx = 2;
  if (has_startidx()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->startidx(), output);
  }

  // required string filename = 3;
  if (has_filename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->filename().data(), this->filename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "filename");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->filename(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Init)
}

::google::protobuf::uint8* Init::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Init)
  // required int32 trunkSize = 1;
  if (has_trunksize()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->trunksize(), target);
  }

  // required int32 startIdx = 2;
  if (has_startidx()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->startidx(), target);
  }

  // required string filename = 3;
  if (has_filename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->filename().data(), this->filename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "filename");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->filename(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Init)
  return target;
}

int Init::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 trunkSize = 1;
    if (has_trunksize()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->trunksize());
    }

    // required int32 startIdx = 2;
    if (has_startidx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->startidx());
    }

    // required string filename = 3;
    if (has_filename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->filename());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Init::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Init* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Init*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Init::MergeFrom(const Init& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_trunksize()) {
      set_trunksize(from.trunksize());
    }
    if (from.has_startidx()) {
      set_startidx(from.startidx());
    }
    if (from.has_filename()) {
      set_filename(from.filename());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Init::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Init::CopyFrom(const Init& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Init::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void Init::Swap(Init* other) {
  if (other != this) {
    std::swap(trunksize_, other->trunksize_);
    std::swap(startidx_, other->startidx_);
    std::swap(filename_, other->filename_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Init::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Init_descriptor_;
  metadata.reflection = Init_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Trunk::kDataFieldNumber;
#endif  // !_MSC_VER

Trunk::Trunk()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Trunk)
}

void Trunk::InitAsDefaultInstance() {
}

Trunk::Trunk(const Trunk& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Trunk)
}

void Trunk::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Trunk::~Trunk() {
  // @@protoc_insertion_point(destructor:Trunk)
  SharedDtor();
}

void Trunk::SharedDtor() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (this != default_instance_) {
  }
}

void Trunk::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Trunk::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Trunk_descriptor_;
}

const Trunk& Trunk::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FileTransfer_2eproto();
  return *default_instance_;
}

Trunk* Trunk::default_instance_ = NULL;

Trunk* Trunk::New() const {
  return new Trunk;
}

void Trunk::Clear() {
  if (has_data()) {
    if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      data_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Trunk::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Trunk)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_data()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->data().data(), this->data().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "data");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Trunk)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Trunk)
  return false;
#undef DO_
}

void Trunk::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Trunk)
  // required string data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "data");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Trunk)
}

::google::protobuf::uint8* Trunk::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Trunk)
  // required string data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->data().data(), this->data().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "data");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Trunk)
  return target;
}

int Trunk::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string data = 1;
    if (has_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->data());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Trunk::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Trunk* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Trunk*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Trunk::MergeFrom(const Trunk& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_data(from.data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Trunk::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Trunk::CopyFrom(const Trunk& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Trunk::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Trunk::Swap(Trunk* other) {
  if (other != this) {
    std::swap(data_, other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Trunk::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Trunk_descriptor_;
  metadata.reflection = Trunk_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

Resume::Resume()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Resume)
}

void Resume::InitAsDefaultInstance() {
}

Resume::Resume(const Resume& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Resume)
}

void Resume::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Resume::~Resume() {
  // @@protoc_insertion_point(destructor:Resume)
  SharedDtor();
}

void Resume::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Resume::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Resume::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Resume_descriptor_;
}

const Resume& Resume::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FileTransfer_2eproto();
  return *default_instance_;
}

Resume* Resume::default_instance_ = NULL;

Resume* Resume::New() const {
  return new Resume;
}

void Resume::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Resume::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Resume)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:Resume)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Resume)
  return false;
#undef DO_
}

void Resume::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Resume)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Resume)
}

::google::protobuf::uint8* Resume::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Resume)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Resume)
  return target;
}

int Resume::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Resume::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Resume* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Resume*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Resume::MergeFrom(const Resume& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Resume::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Resume::CopyFrom(const Resume& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Resume::IsInitialized() const {

  return true;
}

void Resume::Swap(Resume* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Resume::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Resume_descriptor_;
  metadata.reflection = Resume_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

Pause::Pause()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Pause)
}

void Pause::InitAsDefaultInstance() {
}

Pause::Pause(const Pause& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Pause)
}

void Pause::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Pause::~Pause() {
  // @@protoc_insertion_point(destructor:Pause)
  SharedDtor();
}

void Pause::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Pause::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Pause::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Pause_descriptor_;
}

const Pause& Pause::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FileTransfer_2eproto();
  return *default_instance_;
}

Pause* Pause::default_instance_ = NULL;

Pause* Pause::New() const {
  return new Pause;
}

void Pause::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Pause::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Pause)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:Pause)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Pause)
  return false;
#undef DO_
}

void Pause::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Pause)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Pause)
}

::google::protobuf::uint8* Pause::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Pause)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Pause)
  return target;
}

int Pause::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Pause::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Pause* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Pause*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Pause::MergeFrom(const Pause& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Pause::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Pause::CopyFrom(const Pause& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Pause::IsInitialized() const {

  return true;
}

void Pause::Swap(Pause* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Pause::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Pause_descriptor_;
  metadata.reflection = Pause_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

Stop::Stop()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Stop)
}

void Stop::InitAsDefaultInstance() {
}

Stop::Stop(const Stop& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Stop)
}

void Stop::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Stop::~Stop() {
  // @@protoc_insertion_point(destructor:Stop)
  SharedDtor();
}

void Stop::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Stop::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Stop::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Stop_descriptor_;
}

const Stop& Stop::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FileTransfer_2eproto();
  return *default_instance_;
}

Stop* Stop::default_instance_ = NULL;

Stop* Stop::New() const {
  return new Stop;
}

void Stop::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Stop::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Stop)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:Stop)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Stop)
  return false;
#undef DO_
}

void Stop::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Stop)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Stop)
}

::google::protobuf::uint8* Stop::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Stop)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Stop)
  return target;
}

int Stop::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Stop::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Stop* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Stop*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Stop::MergeFrom(const Stop& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Stop::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Stop::CopyFrom(const Stop& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Stop::IsInitialized() const {

  return true;
}

void Stop::Swap(Stop* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Stop::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Stop_descriptor_;
  metadata.reflection = Stop_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
