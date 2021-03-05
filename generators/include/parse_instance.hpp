#pragma once

#define CAT(x) BOOST_PP_SEQ_CAT (x)

#define NL \n
#define TB \t

#define DECL_INSTANCE_EXTENSIONS(z, n, text) \
TB template <> NL \
TB struct extension <n> NL \
TB { NL \
TB TB static constexpr char name [] = CAT ((INSTANCE_EXTENSION_) (n) (_NAME)); NL \
TB }; NL

#define DECL_INSTANCE_LAYERS(z, n, text) \
TB template <> NL \
TB struct layers <n> NL \
TB { NL \
TB TB static constexpr char name [] = CAT ((INSTANCE_LAYER_) (n) (_NAME)); NL \
TB }; NL
