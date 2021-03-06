/*
    Copyright 2015-2016 Amebis
    Copyright 2016 G�ANT

    This file is part of G�ANTLink.

    G�ANTLink is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    G�ANTLink is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with G�ANTLink. If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../EAPBase/include/EAP.h"

namespace eap
{
    ///
    /// TLS packet type
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter: A.1. Record Layer](https://tools.ietf.org/html/rfc5246#appendix-A.1)
    ///
    enum tls_message_type_t;

    ///
    /// TLS handshake type
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter: A.4. Handshake Protocol](https://tools.ietf.org/html/rfc5246#appendix-A.4)
    ///
    enum tls_handshake_type_t;

    ///
    /// TLS alert level
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter: 7.2. Alert Protocol)](https://tools.ietf.org/html/rfc5246#section-7.2)
    ///
    enum tls_alert_level_t;

    ///
    /// TLS alert description
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter: 7.2. Alert Protocol)](https://tools.ietf.org/html/rfc5246#section-7.2)
    ///
    enum tls_alert_desc_t;

    ///
    /// TLS protocol version
    ///
    struct tls_version;
    extern const tls_version tls_version_1_0;
    extern const tls_version tls_version_1_1;
    extern const tls_version tls_version_1_2;

    ///
    /// TLS client/server random
    ///
    struct tls_random;

    ///
    /// Master secret
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (8.1. Computing the Master Secret)](https://tools.ietf.org/html/rfc5246#section-8.1)
    ///
    struct tls_master_secret;

    ///
    /// HMAC padding
    ///
    /// \sa [HMAC: Keyed-Hashing for Message Authentication](https://tools.ietf.org/html/rfc2104)
    ///
    struct hmac_padding;

    ///
    /// Our own implementation of HMAC hashing
    /// Microsoft's implementation ([MSDN](https://msdn.microsoft.com/en-us/library/windows/desktop/aa382379.aspx)) is flaky.
    ///
    /// \sa [HMAC: Keyed-Hashing for Message Authentication](https://tools.ietf.org/html/rfc2104)
    ///
    class hmac_hash;

    ///
    /// TLS client connection state
    ///
    /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter 6.1. Connection States)](https://tools.ietf.org/html/rfc5246#section-6.1)
    ///
    class tls_conn_state;

    ///
    /// EAP-TLS packet
    ///
    class packet_tls;

    ///
    /// TLS map of handshake messages received
    ///
    class tls_handshake_flags;
}

#pragma once

#include <memory>

#include <assert.h>


namespace eap
{
#pragma warning(push)
#pragma warning(disable: 4480)

    enum tls_message_type_t : unsigned char
    {
        tls_message_type_change_cipher_spec = 20,
        tls_message_type_alert              = 21,
        tls_message_type_handshake          = 22,
        tls_message_type_application_data   = 23,
    };


    enum tls_handshake_type_t : unsigned char
    {
        tls_handshake_type_hello_request       =  0,
        tls_handshake_type_client_hello        =  1,
        tls_handshake_type_server_hello        =  2,
        tls_handshake_type_certificate         = 11,
        tls_handshake_type_server_key_exchange = 12,
        tls_handshake_type_certificate_request = 13,
        tls_handshake_type_server_hello_done   = 14,
        tls_handshake_type_certificate_verify  = 15,
        tls_handshake_type_client_key_exchange = 16,
        tls_handshake_type_finished            = 20,

        tls_handshake_type_min                 =  0,    ///< First existing handshake message
        tls_handshake_type_max                 = 21     ///< First non-existing (officially) handshake message
    };


    enum tls_alert_level_t : unsigned char
    {
        tls_alert_level_warning = 1,
        tls_alert_level_fatal   = 2,
    };


    enum tls_alert_desc_t : unsigned char
    {
        tls_alert_desc_close_notify            =   0,
        tls_alert_desc_unexpected_message      =  10,
        tls_alert_desc_bad_record_mac          =  20,
        tls_alert_desc_decryption_failed       =  21, // reserved
        tls_alert_desc_record_overflow         =  22,
        tls_alert_desc_decompression_failure   =  30,
        tls_alert_desc_handshake_failure       =  40,
        tls_alert_desc_no_certificate          =  41, // reserved
        tls_alert_desc_bad_certificate         =  42,
        tls_alert_desc_unsupported_certificate =  43,
        tls_alert_desc_certificate_revoked     =  44,
        tls_alert_desc_certificate_expired     =  45,
        tls_alert_desc_certificate_unknown     =  46,
        tls_alert_desc_illegal_parameter       =  47,
        tls_alert_desc_unknown_ca              =  48,
        tls_alert_desc_access_denied           =  49,
        tls_alert_desc_decode_error            =  50,
        tls_alert_desc_decrypt_error           =  51,
        tls_alert_desc_export_restriction      =  60, // reserved
        tls_alert_desc_protocol_version        =  70,
        tls_alert_desc_insufficient_security   =  71,
        tls_alert_desc_internal_error          =  80,
        tls_alert_desc_user_canceled           =  90,
        tls_alert_desc_no_renegotiation        = 100,
        tls_alert_desc_unsupported_extension   = 110,
    };

#pragma warning(pop)


#pragma pack(push)
#pragma pack(1)
    ///
    /// TLS protocol version
    ///
    struct __declspec(novtable) tls_version
    {
        unsigned char major;    ///< Major version
        unsigned char minor;    ///< Minor version

        ///
        /// Copies a TLS version
        ///
        /// \param[in] other  Version to copy from
        ///
        /// \returns Reference to this object
        ///
        inline tls_version& operator=(_In_ const tls_version &other)
        {
            if (this != std::addressof(other)) {
                major = other.major;
                minor = other.minor;
            }
            return *this;
        }

        ///
        /// Is version less than?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is less than h;
        /// - Zero otherwise.
        ///
        inline bool operator<(_In_ const tls_version &other) const
        {
            return major < other.major || major == other.major && minor < other.minor;
        }

        ///
        /// Is version less than or equal to?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is less than or equal to h;
        /// - Zero otherwise.
        ///
        inline bool operator<=(_In_ const tls_version &other) const
        {
            return !operator>(other);
        }

        ///
        /// Is version greater than or equal to?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is greater than or equal to h;
        /// - Zero otherwise.
        ///
        inline bool operator>=(_In_ const tls_version &other) const
        {
            return !operator<(other);
        }

        ///
        /// Is version greater than?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is greater than h;
        /// - Zero otherwise.
        ///
        inline bool operator>(_In_ const tls_version &other) const
        {
            return other.major < major || other.major == major && other.minor < minor;
        }

        ///
        /// Is version not equal to?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is not equal to h;
        /// - Zero otherwise.
        ///
        inline bool operator!=(_In_ const tls_version &other) const
        {
            return !operator==(other);
        }

        ///
        /// Is version equal to?
        ///
        /// \param[in] other  Protocol version to compare against
        /// \return
        /// - Non zero when protocol version is equal to h;
        /// - Zero otherwise.
        ///
        inline bool operator==(_In_ const tls_version &other) const
        {
            return major == other.major && minor == other.minor;
        }
    };
#pragma pack(pop)


#pragma pack(push)
#pragma pack(1)
    struct __declspec(novtable) tls_random : public sanitizing_blob_xf<32>
    {
        ///
        /// Generate TLS random
        ///
        /// \param[in] cp  Handle of the cryptographics provider
        ///
        void randomize(_In_ HCRYPTPROV cp);
    };
#pragma pack(pop)


#pragma pack(push)
#pragma pack(1)
    struct __declspec(novtable) tls_master_secret : public sanitizing_blob_xf<48>
    {
        ///
        /// Constructor
        ///
        tls_master_secret();

        ///
        /// Constructs a pre-master secret
        ///
        /// \sa [The Transport Layer Security (TLS) Protocol Version 1.2 (Chapter 7.4.7.1. RSA-Encrypted Premaster Secret Message)](https://tools.ietf.org/html/rfc5246#section-7.4.7.1)
        ///
        /// \param[in] cp   Handle of the cryptographics provider
        /// \param[in] ver  TLS version
        ///
        tls_master_secret(_In_ HCRYPTPROV cp, _In_ tls_version ver);

        ///
        /// Copies a master secret
        ///
        /// \param[in] other  Master secret to copy from
        ///
        tls_master_secret(_In_ const sanitizing_blob_f<48> &other);

#ifdef _DEBUG
        ///
        /// Moves the master secret
        ///
        /// \param[inout] other  Master secret to move from
        ///
        tls_master_secret(_Inout_ sanitizing_blob_zf<48> &&other);
#endif
    };
#pragma pack(pop)


#pragma pack(push)
#pragma pack(1)
    struct __declspec(novtable) hmac_padding : public sanitizing_blob_xf<64>
    {
        ///
        /// Constructor
        ///
        hmac_padding();

        ///
        /// Derive padding from secret
        ///
        /// \param[in] cp           Handle of the cryptographics provider
        /// \param[in] alg          Hashing algorithm
        /// \param[in] secret       HMAC secret
        /// \param[in] size_secret  \p secret size
        /// \param[in] pad          Padding value to XOR with (0x36=inner, 0x5c=outer...)
        ///
        hmac_padding(
            _In_                               HCRYPTPROV    cp,
            _In_                               ALG_ID        alg,
            _In_bytecount_(size_secret ) const void          *secret,
            _In_                               size_t        size_secret,
            _In_opt_                           unsigned char pad = 0x36);

        ///
        /// Copies a padding
        ///
        /// \param[in] other  Master secret to copy from
        ///
        hmac_padding(_In_ const sanitizing_blob_f<64> &other);

#ifdef _DEBUG
        ///
        /// Moves the padding
        ///
        /// \param[inout] other  Padding to move from
        ///
        hmac_padding(_Inout_ sanitizing_blob_zf<64> &&other);
#endif
    };
#pragma pack(pop)


    class hmac_hash
    {
    public:
        ///
        /// Construct new HMAC hashing object
        ///
        /// \param[in] cp           Handle of the cryptographics provider
        /// \param[in] alg          Hashing algorithm
        /// \param[in] secret       HMAC secret
        /// \param[in] size_secret  \p secret size
        ///
        hmac_hash(
            _In_                               HCRYPTPROV cp,
            _In_                               ALG_ID     alg,
            _In_bytecount_(size_secret ) const void       *secret,
            _In_                               size_t     size_secret);

        ///
        /// Construct new HMAC hashing object using already prepared inner padding
        ///
        /// \param[in] cp           Handle of the cryptographics provider
        /// \param[in] alg          Hashing algorithm
        /// \param[in] padding      HMAC secret XOR inner padding
        ///
        hmac_hash(
            _In_       HCRYPTPROV   cp,
            _In_       ALG_ID       alg,
            _In_ const hmac_padding &padding);

        ///
        /// Provides access to inner hash object to hash data at will.
        ///
        /// \returns Inner hashing object handle
        ///
        inline operator HCRYPTHASH()
        {
            return m_hash_inner;
        }

        ///
        /// Completes hashing and returns hashed data.
        ///
        /// \param[out] val  Calculated hash value
        ///
        template<class _Ty, class _Ax>
        inline void calculate(_Out_ std::vector<_Ty, _Ax> &val)
        {
            // Calculate inner hash.
            if (!CryptGetHashParam(m_hash_inner, HP_HASHVAL, val, 0))
                throw win_runtime_error(__FUNCTION__ " Error calculating inner hash.");

            // Hash inner hash with outer hash.
            if (!CryptHashData(m_hash_outer, (const BYTE*)val.data(), (DWORD)(val.size() * sizeof(_Ty)), 0))
                throw win_runtime_error(__FUNCTION__ " Error hashing inner hash.");

            // Calculate outer hash.
            if (!CryptGetHashParam(m_hash_outer, HP_HASHVAL, val, 0))
                throw win_runtime_error(__FUNCTION__ " Error calculating outer hash.");
        }

    protected:
        winstd::crypt_hash m_hash_inner; ///< Inner hashing object
        winstd::crypt_hash m_hash_outer; ///< Outer hashing object
    };


    class tls_conn_state
    {
    public:
        ///
        /// Constructs a connection state
        ///
        tls_conn_state();

        ///
        /// Copy a connection state
        ///
        /// \param[in] other  Connection state to copy from
        ///
        tls_conn_state(_In_ const tls_conn_state &other);

        ///
        /// Moves a connection state
        ///
        /// \param[inout] other  Connection state to move from
        ///
        tls_conn_state(_Inout_ tls_conn_state &&other);

        ///
        /// Copy a connection state
        ///
        /// \param[inout] other  Connection state to copy from
        ///
        /// \returns Reference to this object
        ///
        tls_conn_state& operator=(_In_ const tls_conn_state &other);

        ///
        /// Moves a connection state
        ///
        /// \param[in] other  Connection state to move from
        ///
        /// \returns Reference to this object
        ///
        tls_conn_state& operator=(_Inout_ tls_conn_state &&other);

        ///
        /// Configures state according to given cipher
        ///
        /// \param[in] cipher  Cipher ID
        ///
        void set_cipher(_In_ const unsigned char cipher[2]);

    public:
        LPCTSTR m_prov_name;            ///< Cryptography provider name
        DWORD m_prov_type;              ///< Cryptography provider type
        ALG_ID m_alg_encrypt;           ///< Bulk encryption algorithm
        size_t m_size_enc_key;          ///< Encryption key size in bytes (has to comply with `m_alg_encrypt`)
        size_t m_size_enc_iv;           ///< Encryption initialization vector size in bytes (has to comply with `m_alg_encrypt`)
        size_t m_size_enc_block;        ///< Encryption block size in bytes (has to comply with `m_alg_encrypt`)
        winstd::crypt_key m_key;        ///< Key for encrypting messages
        ALG_ID m_alg_mac;               ///< Message authenticy check algorithm
        size_t m_size_mac_key;          ///< Message authenticy check algorithm key size (has to comply with `m_alg_mac`)
        size_t m_size_mac_hash;         ///< Message authenticy check algorithm result size (has to comply with `m_alg_mac`)
        hmac_padding m_padding_hmac;    ///< Padding (key) for HMAC calculation
    };


    class packet_tls : public packet
    {
    public:
#pragma warning(push)
#pragma warning(disable: 4480)

        ///
        /// EAP-TLS request packet flags
        ///
        /// \sa [The EAP-TLS Authentication Protocol (Chapter: 3.1 EAP-TLS Request Packet)](https://tools.ietf.org/html/rfc5216#section-3.1)
        ///
        enum flags_req_t : unsigned char {
            flags_req_length_incl = 0x80,   ///< Length included
            flags_req_more_frag   = 0x40,   ///< More fragments
            flags_req_start       = 0x20,   ///< Start
        };

        ///
        /// EAP-TLS response packet flags
        ///
        /// \sa [The EAP-TLS Authentication Protocol (Chapter: 3.2 EAP-TLS Response Packet)](https://tools.ietf.org/html/rfc5216#section-3.2)
        ///
        enum flags_res_t : unsigned char {
            flags_res_length_incl = 0x80,   ///< Length included
            flags_res_more_frag   = 0x40,   ///< More fragments
        };

#pragma warning(pop)

    public:
        ///
        /// Constructs an empty packet
        ///
        packet_tls();

        ///
        /// Copies a packet
        ///
        /// \param[in] other  Packet to copy from
        ///
        packet_tls(_In_ const packet_tls &other);

        ///
        /// Moves a packet
        ///
        /// \param[in] other  Packet to move from
        ///
        packet_tls(_Inout_ packet_tls &&other);

        ///
        /// Copies a packet
        ///
        /// \param[in] other  Packet to copy from
        ///
        /// \returns Reference to this object
        ///
        packet_tls& operator=(_In_ const packet_tls &other);

        ///
        /// Moves a packet
        ///
        /// \param[in] other  Packet to move from
        ///
        /// \returns Reference to this object
        ///
        packet_tls& operator=(_Inout_ packet_tls &&other);

        ///
        /// Empty the packet
        ///
        virtual void clear();

        ///
        /// Appends fragment
        ///
        /// \param[in] pck  EAP packet fragment
        ///
        /// \returns
        /// - \c true  if this was the last fragment of a packet
        /// - \c false if more fragments are to follow
        ///
        bool append_frag(_In_ const EapPacket *pck);

        ///
        /// Gets next fragment of the packet
        ///
        /// \param[out  ] pck       Memory to write EAP packet to
        /// \param[inout] size_max  Available size of \p pck (in bytes)
        ///
        /// \returns Final size of the packet (fragment)
        ///
        unsigned short get_frag(_Out_bytecap_(size_max) EapPacket *pck, _In_ size_t size_max);

        ///
        /// Is this packet an ACK
        ///
        /// \param[in] id  ID of originating EAP packet
        ///
        inline bool is_ack(_In_ unsigned char id) const
        {
            return
                m_code == EapCodeRequest &&
                m_id   == id             &&
                m_data.empty()           &&
                !(m_flags & (flags_req_length_incl | flags_req_more_frag | flags_req_start));
        }

    public:
        unsigned char m_flags;  ///< Packet flags
    };


    class tls_handshake_flags
    {
    public:
        ///
        /// Constructs an empty set of flags
        ///
        inline tls_handshake_flags()
        {
            memset(m_flags, 0, sizeof(m_flags));
        }

        ///
        /// Empty set of flags
        ///
        inline void clear()
        {
            memset(m_flags, 0, sizeof(m_flags));
        }

        ///
        /// Set particular flag
        ///
        /// \param[in] type  TLS handshake message to set its flag
        ///
        inline void set(_In_ tls_handshake_type_t type)
        {
            assert(tls_handshake_type_min <= type && type < tls_handshake_type_max);
            m_flags[type] = true;
        }

        ///
        /// Get particular flag
        ///
        /// \param[in] type  TLS handshake message to get its flag
        ///
        inline bool operator[](_In_ tls_handshake_type_t type) const
        {
            assert(tls_handshake_type_min <= type && type < tls_handshake_type_max);
            return m_flags[type];
        }

    protected:
        bool m_flags[tls_handshake_type_max];   ///< Set of flags
    };
}
