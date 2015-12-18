// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RpcMessage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "RpcMessage.pb.h"

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

namespace maxiaoda {

namespace {

const ::google::protobuf::Descriptor* RpcMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RpcMessage_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* MessageType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* ErrorReason_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_RpcMessage_2eproto() {
  protobuf_AddDesc_RpcMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "RpcMessage.proto");
  GOOGLE_CHECK(file != NULL);
  RpcMessage_descriptor_ = file->message_type(0);
  static const int RpcMessage_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, service_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, method_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, contend_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, error_),
  };
  RpcMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RpcMessage_descriptor_,
      RpcMessage::default_instance_,
      RpcMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RpcMessage));
  MessageType_descriptor_ = file->enum_type(0);
  ErrorReason_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_RpcMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RpcMessage_descriptor_, &RpcMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_RpcMessage_2eproto() {
  delete RpcMessage::default_instance_;
  delete RpcMessage_reflection_;
}

void protobuf_AddDesc_RpcMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020RpcMessage.proto\022\010maxiaoda\"\225\001\n\nRpcMess"
    "age\022#\n\004type\030\001 \002(\0162\025.maxiaoda.MessageType"
    "\022\n\n\002id\030\002 \002(\005\022\017\n\007service\030\003 \001(\t\022\016\n\006method\030"
    "\004 \001(\t\022\017\n\007contend\030\005 \001(\014\022$\n\005error\030\006 \001(\0162\025."
    "maxiaoda.ErrorReason*3\n\013MessageType\022\013\n\007R"
    "EQUEST\020\000\022\014\n\010RESPONSE\020\001\022\t\n\005ERROR\020\002*\035\n\013Err"
    "orReason\022\016\n\nUKNOWERROR\020\000", 264);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "RpcMessage.proto", &protobuf_RegisterTypes);
  RpcMessage::default_instance_ = new RpcMessage();
  RpcMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_RpcMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_RpcMessage_2eproto {
  StaticDescriptorInitializer_RpcMessage_2eproto() {
    protobuf_AddDesc_RpcMessage_2eproto();
  }
} static_descriptor_initializer_RpcMessage_2eproto_;
const ::google::protobuf::EnumDescriptor* MessageType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageType_descriptor_;
}
bool MessageType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* ErrorReason_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ErrorReason_descriptor_;
}
bool ErrorReason_IsValid(int value) {
  switch(value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int RpcMessage::kTypeFieldNumber;
const int RpcMessage::kIdFieldNumber;
const int RpcMessage::kServiceFieldNumber;
const int RpcMessage::kMethodFieldNumber;
const int RpcMessage::kContendFieldNumber;
const int RpcMessage::kErrorFieldNumber;
#endif  // !_MSC_VER

RpcMessage::RpcMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:maxiaoda.RpcMessage)
}

void RpcMessage::InitAsDefaultInstance() {
}

RpcMessage::RpcMessage(const RpcMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:maxiaoda.RpcMessage)
}

void RpcMessage::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0;
  id_ = 0;
  service_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  method_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  contend_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  error_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RpcMessage::~RpcMessage() {
  // @@protoc_insertion_point(destructor:maxiaoda.RpcMessage)
  SharedDtor();
}

void RpcMessage::SharedDtor() {
  if (service_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete service_;
  }
  if (method_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete method_;
  }
  if (contend_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete contend_;
  }
  if (this != default_instance_) {
  }
}

void RpcMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RpcMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RpcMessage_descriptor_;
}

const RpcMessage& RpcMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RpcMessage_2eproto();
  return *default_instance_;
}

RpcMessage* RpcMessage::default_instance_ = NULL;

RpcMessage* RpcMessage::New() const {
  return new RpcMessage;
}

void RpcMessage::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RpcMessage*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(type_, id_);
    if (has_service()) {
      if (service_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        service_->clear();
      }
    }
    if (has_method()) {
      if (method_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        method_->clear();
      }
    }
    if (has_contend()) {
      if (contend_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        contend_->clear();
      }
    }
    error_ = 0;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RpcMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:maxiaoda.RpcMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .maxiaoda.MessageType type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::maxiaoda::MessageType_IsValid(value)) {
            set_type(static_cast< ::maxiaoda::MessageType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // required int32 id = 2;
      case 2: {
        if (tag == 16) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_service;
        break;
      }

      // optional string service = 3;
      case 3: {
        if (tag == 26) {
         parse_service:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_service()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->service().data(), this->service().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "service");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_method;
        break;
      }

      // optional string method = 4;
      case 4: {
        if (tag == 34) {
         parse_method:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->method().data(), this->method().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "method");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_contend;
        break;
      }

      // optional bytes contend = 5;
      case 5: {
        if (tag == 42) {
         parse_contend:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_contend()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_error;
        break;
      }

      // optional .maxiaoda.ErrorReason error = 6;
      case 6: {
        if (tag == 48) {
         parse_error:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::maxiaoda::ErrorReason_IsValid(value)) {
            set_error(static_cast< ::maxiaoda::ErrorReason >(value));
          } else {
            mutable_unknown_fields()->AddVarint(6, value);
          }
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
  // @@protoc_insertion_point(parse_success:maxiaoda.RpcMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:maxiaoda.RpcMessage)
  return false;
#undef DO_
}

void RpcMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:maxiaoda.RpcMessage)
  // required .maxiaoda.MessageType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // required int32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->id(), output);
  }

  // optional string service = 3;
  if (has_service()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->service().data(), this->service().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "service");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->service(), output);
  }

  // optional string method = 4;
  if (has_method()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "method");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->method(), output);
  }

  // optional bytes contend = 5;
  if (has_contend()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->contend(), output);
  }

  // optional .maxiaoda.ErrorReason error = 6;
  if (has_error()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->error(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:maxiaoda.RpcMessage)
}

::google::protobuf::uint8* RpcMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:maxiaoda.RpcMessage)
  // required .maxiaoda.MessageType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // required int32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->id(), target);
  }

  // optional string service = 3;
  if (has_service()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->service().data(), this->service().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "service");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->service(), target);
  }

  // optional string method = 4;
  if (has_method()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "method");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->method(), target);
  }

  // optional bytes contend = 5;
  if (has_contend()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->contend(), target);
  }

  // optional .maxiaoda.ErrorReason error = 6;
  if (has_error()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->error(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:maxiaoda.RpcMessage)
  return target;
}

int RpcMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .maxiaoda.MessageType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // required int32 id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional string service = 3;
    if (has_service()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->service());
    }

    // optional string method = 4;
    if (has_method()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->method());
    }

    // optional bytes contend = 5;
    if (has_contend()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->contend());
    }

    // optional .maxiaoda.ErrorReason error = 6;
    if (has_error()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->error());
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

void RpcMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RpcMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RpcMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RpcMessage::MergeFrom(const RpcMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_service()) {
      set_service(from.service());
    }
    if (from.has_method()) {
      set_method(from.method());
    }
    if (from.has_contend()) {
      set_contend(from.contend());
    }
    if (from.has_error()) {
      set_error(from.error());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RpcMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcMessage::CopyFrom(const RpcMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void RpcMessage::Swap(RpcMessage* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(id_, other->id_);
    std::swap(service_, other->service_);
    std::swap(method_, other->method_);
    std::swap(contend_, other->contend_);
    std::swap(error_, other->error_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RpcMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RpcMessage_descriptor_;
  metadata.reflection = RpcMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace maxiaoda

// @@protoc_insertion_point(global_scope)
