// Copyright (c) 2012, Thomas Goyne <plorkyeran@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#pragma once

#include <string>
#include <string_view>

namespace agi {
	struct Color {
		unsigned char r = 0;	///< Red component
		unsigned char g = 0;	///< Green component
		unsigned char b = 0;	///< Blue component
		unsigned char a = 0;	///< Alpha component

		Color() = default;
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0);
		Color(std::string_view str);

		bool operator==(Color const&) const noexcept = default;

		std::string GetAssStyleFormatted() const;
		std::string GetAssOverrideFormatted() const;
		std::string GetSsaFormatted() const;
		std::string GetHexFormatted(bool rgba=false) const;
		std::string GetRgbFormatted() const;

		operator std::string() const { return GetRgbFormatted(); }
	};
}
