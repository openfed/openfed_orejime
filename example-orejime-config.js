var orejimeConfig = {
  privacyPolicy: "#privacyPolicy",
  default: true,
  gdprCompliant: true,
  apps: [
    {
      name: "google-tag-manager",
      title: "Google Tag Manager",
      cookies: [
        "_ga",
        "_gat",
        "_gid",
        "__utma",
        "__utmb",
        "__utmc",
        "__utmt",
        "__utmz",
        "_gat_gtag_" + Drupal.settings.orejime_openfed.GTM_UA,
        "_gat_" + Drupal.settings.orejime_openfed.GTM_UA
      ],
      purposes: ["analytics"],
      callback: function(consent, app){
        console.log("User consent for app " + app.name + ": consent=" + consent)
      },
      required: false,
      optOut: false,
      default: true,
      onlyOnce: true,
    },
    {
      name: "google-analytics",
      title: "Google Analytics",
      cookies: [
        "_ga",
        "_gat",
        "_gid",
        "__utma",
        "__utmb",
        "__utmc",
        "__utmt",
        "__utmz",
        "AMP_TOKEN",
        "_gac_" + Drupal.settings.orejime_openfed.GTM_UA
      ],
      purposes: ["analytics"],
      callback: function(consent, app){
        // This is an example callback function.
        console.log("User consent for app " + app.name + ": consent=" + consent)
      },
      required: false,
      optOut: false,
      default: true,
      onlyOnce: true,
    },
    {
      name: "inline-tracker",
      title: "Inline Tracker",
      purposes: ["analytics"],
      cookies: ["inline-tracker"]
    },
    {
      name: "external-tracker",
      title: "External Tracker",
      purposes: ["analytics", "security"],
      cookies: ["external-tracker"],
    },
    {
      name: "disabled-by-default",
      title: "Something disabled by default",
      purposes: ["ads"]
    },
    {
      name: "always-on",
      title: "Required app",
      purposes: [],
      required: true
    }
  ],
};
